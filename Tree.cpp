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
    if (this->_root == nullptr)
    {
        throw std::invalid_argument("the tree is empty as for now - there is no root");
    }
    return (this->_root->getValue());
}

//parent method
int ariel::Tree::parent(int i)
{
    if (this->_root == nullptr || this->size() == 0)
    {
        throw std::invalid_argument("this tree is empty!");
    }
    if (!(this->contains(i)))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no such node with the key: " + nodeValue + " in this tree");
    }
    if (this->_root->getValue() == i)
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument(nodeValue + " is the root of the tree - it has no parent");
    }
    return (ariel::Tree::parent(this->_root, i));
}

//parent private supporting method
int ariel::Tree::parent(TreeNode *current, int i)
{
    if (current == nullptr)
    {
        throw std::invalid_argument("no such node NULLPTR");
    }
    if ((current->getLeftSon() == nullptr) && (current->getRightSon() == nullptr))
    {
        throw std::invalid_argument("no such node NULLSONS");
    }
    if ((current->getLeftSon() != nullptr && current->getLeftSon()->getValue() == i) || (current->getRightSon() != nullptr && current->getRightSon()->getValue() == i))
    {
        return current->getValue();
    }
    if (current->getValue() > i)
        return ariel::Tree::parent(current->getLeftSon(), i);

    if (current->getValue() < i)
        return ariel::Tree::parent(current->getRightSon(), i);
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
    {
        std::cout << std::endl;
        return;
    }
    /* first recur on left child */
    print(current->getLeftSon());
    /* then print the data of node */
    std::cout << current->getValue() << " ";
    /* now recur on right child */
    print(current->getRightSon());
}

//remove method
void ariel::Tree::remove(int i)
{
    //in case the tree is empty - > throw exception
    if (this->_root == nullptr)
    {
        throw std::invalid_argument("you are trying to remove node from an empty tree");
    }
    //in case the tree doesnt hold asked value to remove - > throw exception
    if (!(this->contains(i)))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no node with the key: " + nodeValue + " in this tree");
    }
    //in case asked value is the root - which has no "kids" (and the last "if" didnt catch us - which means asked node is the root)
    if ((this->_root->getLeftSon() == nullptr) && (this->_root->getRightSon() == nullptr))
    {
        this->_root = nullptr;
        return;
    }
    //in case all these conditions are false
    ariel::Tree::remove(this->_root, i);
}

//remove private supporting method
void ariel::Tree::remove(TreeNode *current, int i)
{
    //if current node holds the value asked to remove - we'll adress some cases
    if (current->getValue() == i)
    {
        //if the node has NO childern (and is not the root) - just remove it by making its father son -  a nullptr
        if ((current->getLeftSon() == nullptr) && (current->getRightSon() == nullptr))
        {
            TreeNode *parent = ariel::Tree::findParent(this->_root, i);
            if ((parent->getLeftSon() != nullptr) && (parent->getLeftSon()->getValue() == i))
            {
                parent->setLeftSon(nullptr);
            }
            else if (parent->getRightSon() != nullptr)
            {
                parent->setRightSon(nullptr);
            }
            return;
        }
        //in case the asked-to remove node has ONLY left son - > we'll push this son instead of the node
        else if (((current->getLeftSon() != nullptr) && (current->getRightSon() == nullptr)))
        {
            *current = *(current->getLeftSon());
            return;
        }
        //in case the asked-to remove node has ONLY right son - > we'll push this son instead of the node
        else if (((current->getLeftSon() == nullptr) && (current->getRightSon() != nullptr)))
        {

            *current = *(current->getRightSon());
            return;
        }
        //in case the asked-to remove node has both left and right sons - >
        //we'll find the minimum valued node from the right sub tree of this node sons - >
        //if found node is the right son of the one we'll remove - >
        //we'll attach the left subtree of sons from the about-to-be deleted node to the minimum valued one - >
        //and push the minimum valued node as the "top"(first if)//////////////////////////////////////////
        //if the minimum valued node is in the left sub tree of the first right son of the node we are about to delete ->
        //we'll switch the values of them both and delete the minimum valued one (second if)
        else
        {
            TreeNode *tempOfMinFromRight = ariel::Tree::findMin(current->getRightSon());
            TreeNode *parentOfMin = ariel::Tree::findParent(this->_root, tempOfMinFromRight->getValue());
            if (tempOfMinFromRight->getValue() == current->getRightSon()->getValue())
            {
                tempOfMinFromRight->setLeftSon(current->getLeftSon());
                *current = *(current->getRightSon());
                return;
            }
            else
            {
                current->setValue(tempOfMinFromRight->getValue());
                parentOfMin->setLeftSon(nullptr);
                return;
            }
        }
    }
    else if (current->getValue() > i)
    {
        remove(current->getLeftSon(), i);
    }
    else if (current->getValue() < i)
    {
        remove(current->getRightSon(), i);
    }
}
//private supporting method to "help" remove method in case both children exist
TreeNode *ariel::Tree::findMin(TreeNode *current)
{
    if (current->getLeftSon() == nullptr)
    {
        return (current);
    }
    else
    {
        return (ariel::Tree::findMin(current->getLeftSon()));
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
    if (current != nullptr)
    {
        ariel::Tree::destroyTree(current->getLeftSon());
        ariel::Tree::destroyTree(current->getRightSon());
        delete current;
    }
}
TreeNode *ariel::Tree::findParent(TreeNode *current, int i)
{
    if (current == nullptr)
    {
        throw std::invalid_argument("no such node NULLPTR");
    }
    if ((current->getLeftSon() == nullptr) && (current->getRightSon() == nullptr))
    {
        throw std::invalid_argument("no such node NULLSONS");
    }
    if ((current->getLeftSon() != nullptr && current->getLeftSon()->getValue() == i) || (current->getRightSon() != nullptr && current->getRightSon()->getValue() == i))
    {
        return current;
    }
    if (current->getValue() > i)
        return ariel::Tree::findParent(current->getLeftSon(), i);

    if (current->getValue() < i)
        return ariel::Tree::findParent(current->getRightSon(), i);
}
