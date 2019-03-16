#include "Tree.hpp"
#include <iostream>
//constuctors
ariel::Tree::Tree()
{
    this->_root = nullptr;
}

//insert method
void ariel::Tree::insert(int i)
{
    if (this->contains(i))
    {
        throw("there is already a member with the key!!");
    }
    else if (this->_root == nullptr)
    {
        this->_root = new TreeNode(i);
    }
    else
    {
        return (ariel::Tree::insert(this->_root, i));
    }
}

void ariel::Tree::insert(TreeNode *current, int i)
{
   if(current->getValue() > i){
       if(current->getLeftSon()==nullptr){
           TreeNode *newNode = new TreeNode(i);
           current->setLeftSon(newNode);
       }
       else{
           ariel::Tree::insert((current->getLeftSon()), i);
       }
   }
   else{
       if(current->getRightSon()==nullptr){
           TreeNode *newNode = new TreeNode(i);
           current->setRightSon(newNode);
       }
       else{
           ariel::Tree::insert((current->getRightSon()), i);
       }
   }

}

//contains method
bool ariel::Tree::contains(int i)
{
    return (Tree::contains(this->_root, i));
}

bool ariel::Tree::contains(TreeNode *current, int i)
{
    if (current == nullptr)
    {
        return false;
    }
    else if (current->getValue() > i)
    {
        contains(current->getRightSon(), i);
    }
    else
    {
        contains(current->getLeftSon(), i);
    }
}

//size method
int ariel::Tree::size()
{
    return (ariel::Tree::size(this->_root));
}

int ariel::Tree::size(TreeNode *current)
{
    if (current == nullptr)
        return 0;
    else
        return (ariel::Tree::size(current->getLeftSon()) + 1 + ariel::Tree::size(current->getRightSon()));
}

int ariel::Tree::root()
{
    return (this->_root->getValue());
}

//contains method
int ariel::Tree::parent(int i)
{
    if (!this->contains(i))
    {
        throw("no such node in this three");
    }
    return (Tree::parent(this->_root, i));
}

int ariel::Tree::parent(TreeNode *current, int i)
{
    if ((current->getLeftSon()->getValue() == i) || (current->getRightSon()->getValue() == i))
    {
        return (current->getValue());
    }
    else if (current->getValue() > i)
    {
        contains(current->getLeftSon(), i);
    }
    else
    {
        contains(current->getRightSon(), i);
    }
}

int ariel::Tree::left(int i)
{
    if (!this->contains(i))
    {
        throw("no such node !");
    }
    return (Tree::left(this->_root, i));
}

int ariel::Tree::left(TreeNode *current, int i)
{
    if ((current->getValue() == i))
    {
        if (current->getLeftSon() == nullptr)
        {
            throw(" this node has no left son");
        }
        else
        {
            return (current->getLeftSon()->getValue());
        }
    }
    else if (current->getValue() > i)
    {
        contains(current->getLeftSon(), i);
    }
    else
    {
        contains(current->getRightSon(), i);
    }
}

int ariel::Tree::right(int i)
{
    if (!this->contains(i))
    {
        throw("no such node !");
    }
    return (Tree::right(this->_root, i));
}

int ariel::Tree::right(TreeNode *current, int i)
{
    if ((current->getValue() == i))
    {
        if (current->getRightSon() == nullptr)
        {
            throw(" this node has no right son");
        }
        else
        {
            return (current->getRightSon()->getValue());
        }
    }
    else if (current->getValue() > i)
    {
        contains(current->getLeftSon(), i);
    }
    else
    {
        contains(current->getRightSon(), i);
    }
}

void ariel::Tree::print()
{
    ariel::Tree::print(this->_root);
}

void ariel::Tree::print(TreeNode *current)
{
    if (current == nullptr)
        return;
    current->print();
    if (current->getLeftSon() != nullptr)
    {
        Tree::print(current->getLeftSon());
    }
    if (current->getRightSon() != nullptr)
    {
        Tree::print(current->getRightSon());
    }
}