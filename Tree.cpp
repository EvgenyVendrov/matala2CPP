#include "Tree.hpp"
#include "TreeNode.hpp"

//constuctor
ariel::Tree::Tree()
{
    this->_root = nullptr;
}

//insert method
void ariel::Tree::insert(int i)
{
    if (this->contains(i))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is already a node with the key:" + nodeValue + " in this tree");
    }
    if (this->_root == nullptr)
    {
        this->_root = new TreeNode(i);
    }
    else
    {
        ariel::Tree::insert(this->_root, i);
    }
}

//insert private supporting method
void ariel::Tree::insert(TreeNode *current, int i)
{
    if (current->getValue() > i)
    {
        if (current->getLeftSon() == nullptr)
        {
            TreeNode *newNode = new TreeNode(i);
            current->setLeftSon(newNode);
        }
        else
        {
            ariel::Tree::insert((current->getLeftSon()), i);
        }
    }
    else
    {
        if (current->getRightSon() == nullptr)
        {
            TreeNode *newNode = new TreeNode(i);
            current->setRightSon(newNode);
        }
        else
        {
            ariel::Tree::insert((current->getRightSon()), i);
        }
    }
}

//contains method
bool ariel::Tree::contains(int i)
{
    return (ariel::Tree::contains(this->_root, i));
}

//contains private supporting method
bool ariel::Tree::contains(TreeNode *current, int i)
{
    if (current == nullptr)
    {
        return false;
    }
    else if (current->getValue() == i)
    {
        return true;
    }
    else if (current->getValue() > i)
    {
        return (contains(current->getLeftSon(), i));
    }
    else
    {
        return (contains(current->getRightSon(), i));
    }
}

//size method
int ariel::Tree::size()
{
    return (ariel::Tree::size(this->_root));
}

//size private supporting method
int ariel::Tree::size(TreeNode *current)
{
    if (current == nullptr)
        return 0;
    else
        return (ariel::Tree::size(current->getLeftSon()) + 1 + ariel::Tree::size(current->getRightSon()));
}

//root method
int ariel::Tree::root()
{
    return (this->_root->getValue());
}

//parent method
int ariel::Tree::parent(int i)
{
    if (!(this->contains(i)))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no such node with the key: " + nodeValue + " in this tree");
    }
    return (Tree::parent(this->_root, i));
}

//parent private supporting method
int ariel::Tree::parent(TreeNode *current, int i)
{
    if ((current->getLeftSon()->getValue() == i) || (current->getRightSon()->getValue() == i))
    {
        return (current->getValue());
    }
    else if (current->getValue() > i)
    {
        return (parent(current->getLeftSon(), i));
    }
    else
    {
        return (parent(current->getRightSon(), i));
    }
}

//left method
int ariel::Tree::left(int i)
{
    if (!this->contains(i))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no node with the key: " + nodeValue + " in this tree");
    }
    return (Tree::left(this->_root, i));
}

//left private supporting method
int ariel::Tree::left(TreeNode *current, int i)
{
    if ((current->getValue() == i))
    {
        if (current->getLeftSon() == nullptr)
        {
            std::string nodeValue = std::to_string(i);
            throw std::invalid_argument("the node with the key: " + nodeValue + " has no left son");
        }
        else
        {
            return (current->getLeftSon()->getValue());
        }
    }
    else if (current->getValue() > i)
    {
        return (left(current->getLeftSon(), i));
    }
    else
    {
        return (left(current->getRightSon(), i));
    }
}

//right method
int ariel::Tree::right(int i)
{
    if (!this->contains(i))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no node with the key: " + nodeValue + " in this tree");
    }
    return (Tree::right(this->_root, i));
}

//right private supporting method
int ariel::Tree::right(TreeNode *current, int i)
{
    if ((current->getValue() == i))
    {
        if (current->getRightSon() == nullptr)
        {
            std::string nodeValue = std::to_string(i);
            throw std::invalid_argument("the node with the key: " + nodeValue + " has no right son");
        }
        else
        {
            return (current->getRightSon()->getValue());
        }
    }
    else if (current->getValue() > i)
    {
        return (right(current->getLeftSon(), i));
    }
    else
    {
        return (right(current->getRightSon(), i));
    }
}

//print method
void ariel::Tree::print()
{
    ariel::Tree::print(this->_root);
}

//print private supporting method
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

//remove method
void ariel::Tree::remove(int i)
{
    if (this->_root == nullptr)
    {
        throw std::invalid_argument("you are trying to remove node from an empty tree");
    }
    if (!(this->contains(i)))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no node with the key: " + nodeValue + " in this tree");
    }

    ariel::Tree::remove(this->_root, i);
}

//remove private supporting method
void ariel::Tree::remove(TreeNode *current, int i)
{
    if ((current->getValue() == i))
    {
        current = nullptr;
        return;
    }
    else if (current->getValue() > i)
    {
        remove(current->getLeftSon(), i);
    }
    else
    {
        remove(current->getRightSon(), i);
    }
}

//destructor
ariel::Tree::~Tree()
{
    if (this->_root != nullptr)
        ariel::Tree::destroyTree(this->_root);
}

//private supporting method for destructor
void ariel::Tree::destroyTree(TreeNode *current)
{
    if (current != nullptr){
        ariel::Tree::destroyTree(current->getLeftSon());
        ariel::Tree::destroyTree(current->getRightSon());
        delete current;
    }
}