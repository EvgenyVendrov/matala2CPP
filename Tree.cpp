#include "Tree.hpp"
//*******************Tree Node class implementation*******************

TreeNode::TreeNode()
{
    this->_value = 0;
    this->_leftSon = nullptr;
    this->_rightSon = nullptr;
}

TreeNode::TreeNode(int value, TreeNode rightSon, TreeNode leftSon)
{
    this->_value = value;
    *(this->_leftSon) = leftSon;
    *(this->_rightSon) = rightSon;
}

TreeNode::TreeNode(int value)
{
    this->_value = value;
    this->_leftSon = nullptr;
    this->_rightSon = nullptr;
}

void TreeNode::setValue(int value)
{
    this->_value = value;
}

void TreeNode::setLeftSon(TreeNode *leftSon)
{
    this->_leftSon = leftSon;
}

void TreeNode::setRightSon(TreeNode *rightSon)
{
    this->_rightSon = rightSon;
}

int TreeNode::getValue()
{
    return (this->_value);
}

TreeNode *TreeNode::getLeftSon()
{
    return (this->_leftSon);
}

TreeNode *TreeNode::getRightSon()
{
    return (this->_rightSon);
}

void TreeNode::print()
{
    std::cout << (this->getValue()) << "  ";
}

//*******************Tree class implementation*******************

/////////////////////////////////////////////////////////////////
//******************************PUBLIC METHODS*******************
////////////////////////////////////////////////////////////////
//constuctor
ariel::Tree::Tree()
{
    this->_root = nullptr;
    this->_sizeOfTree = 0;
}

void ariel::Tree::insert(int i)
{
    //if the tree is empty - > create a new node with the value of input as the root
    if (this->isEmpty())
    {
        this->_root = new TreeNode(i);
        //increasing the vriable which saves tree's size
        this->_sizeOfTree++;
    }
    //if inserted node has value which is already found in the tree - > throw exception as we don't allow nodes with same values in the tree
    else if (this->contains(i))
    {
        std::string nodeValue = std::to_string(i);
        std::string DEBUG = std::to_string(this->_sizeOfTree);
        throw std::invalid_argument("there is already a node with the key:" + nodeValue + " in this tree");
    }
    //if non of the conditions is true - > go on to the private supporting method of insert (method overloading)
    else
    {
        ariel::Tree::insert(this->_root, i);
    }
}

bool ariel::Tree::contains(int i)
{
    //if the tree is empty - > it dosen't contain any nodes - > return false
    if (this->isEmpty())
    {
        return (false);
    }
    //if the tree isn't empty - > go on to the private supporting method of contains (method overloading)
    return (ariel::Tree::contains(this->_root, i));
}

int ariel::Tree::size()
{
    //returning the static variable which saves how many nodes are in the tree
    return (ariel::Tree::_sizeOfTree);
}

int ariel::Tree::root()
{
    //if the tree is empty - > throw exception
    if (this->isEmpty())
    {
        throw std::invalid_argument("the tree is empty as for now - there is no root");
    }
    //if the tree isnt empty - > return roots value
    return (this->_root->getValue());
}

int ariel::Tree::parent(int i)
{
    //if the tree is empty - > there are certainly no nodes - > throw exception
    if (this->isEmpty())
    {
        throw std::invalid_argument("this tree is empty!");
    }
    //if input node isn't in the tree - > it certanliy has no parent - > throwing exception
    if (!(this->contains(i)))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no such node with the key: " + nodeValue + " in this tree");
    }
    //if the root has the value of asked node - > throw exception as root has no parent
    if (this->_root->getValue() == i)
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument(nodeValue + " is the root of the tree - it has no parent");
    }
    //if non of the conditions are true - > go on to the private supporting method of parent (method overloading)
    return (ariel::Tree::parent(this->_root, i));
}

int ariel::Tree::left(int i)
{
    //if input node isn't in the tree - > it certanliy has no left son - > throwing exception
    if (!this->contains(i))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no node with the key: " + nodeValue + " in this tree");
    }
    //if the node is contained in the tree - > go on to the private supporting method of left (method overloading)
    return (Tree::left(this->_root, i));
}

int ariel::Tree::right(int i)
{
    //if input node isn't in the tree - > it certanliy has no right son - > throwing exception
    if (!this->contains(i))
    {
        std::string nodeValue = std::to_string(i);
        throw std::invalid_argument("there is no node with the key: " + nodeValue + " in this tree");
    }
    //if the node is contained in the tree - > go on to the private supporting method of right (method overloading)
    return (Tree::right(this->_root, i));
}

void ariel::Tree::print()
{
    if (this->isEmpty())
    {
        std::cout << "" << std::endl;
    }
    //go on to the private supporting method of print (method overloading)
    ariel::Tree::print(this->_root);
}

void ariel::Tree::remove(int i)
{
    //in case the tree is empty - > throw exception
    if (this->isEmpty())
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
        //reducing the variable which saves the size of the tree
        this->_sizeOfTree--;
        return;
    }
    //in case all these conditions are false
    ariel::Tree::remove(this->_root, i);
}

//destructor
ariel::Tree::~Tree()
{
    //if the tree isn't empty - > go on to the private supporting method destroyTree(method overloading)
    if (!this->isEmpty()){
        ariel::Tree::destroyTree(this->_root);
        this->_sizeOfTree = 0;
    }
}

//////////////////////////////////////////////////////////////////
//******************************PRIVATE METHODS*******************
/////////////////////////////////////////////////////////////////

//insert private supporting method
void ariel::Tree::insert(TreeNode *current, int i)
{
    //searching the right place to insert the input node - based on SBT structure:
    //if node's value is too large - > check if it has left son - > if it does - > keep recursively searching the right place to insert
    //if there is no left son - > this new - node will attach to the tree as this node left son
    if (current->getValue() > i)
    {
        if (current->getLeftSon() == nullptr)
        {
            TreeNode *newNode = new TreeNode(i);
            current->setLeftSon(newNode);
            //increasing the vriable which saves tree's size
            this->_sizeOfTree++;
        }
        else
        {
            ariel::Tree::insert((current->getLeftSon()), i);
        }
    }
    //if node's value is too small - > check if it has right son - > if it does - > keep recursively searching the right place to insert
    //if there is no right son - > this new - node will attach to the tree as this node right son
    else
    {
        if (current->getRightSon() == nullptr)
        {
            TreeNode *newNode = new TreeNode(i);
            current->setRightSon(newNode);
            //increasing the vriable which saves tree's size
            this->_sizeOfTree++;
        }
        else
        {
            ariel::Tree::insert((current->getRightSon()), i);
        }
    }
}

//contains private supporting method
bool ariel::Tree::contains(TreeNode *current, int i)
{
    //if this current node has the value we're looking for - > return true
    if (current->getValue() == i)
    {
        return true;
    }
    //if this current node has different value than the one we're looking for - >
    //checking if it has suitable son - > if not - > return false - > if it does - > keep searching
    else if (current->getValue() > i)
    {
        if (current->getLeftSon() == nullptr)
        {
            return false;
        }
        return (contains(current->getLeftSon(), i));
    }
    else
    {

        if (current->getRightSon() == nullptr)
        {
            return false;
        }
        return (contains(current->getRightSon(), i));
    }
}

//parent private supporting method
int ariel::Tree::parent(TreeNode *current, int i)
{
    //in case on of this current node sons has the value we're looking for - > return this node value as it's the father
    if ((current->getLeftSon() != nullptr && current->getLeftSon()->getValue() == i) || (current->getRightSon() != nullptr && current->getRightSon()->getValue() == i))
    {
        return current->getValue();
    }
    //looking for the father based on BST structure
    if (current->getValue() > i)
        return ariel::Tree::parent(current->getLeftSon(), i);

    return ariel::Tree::parent(current->getRightSon(), i);
}

//left private supporting method
int ariel::Tree::left(TreeNode *current, int i)
{
    //if this current node has the value we're looking for - > check if it has a left son and return the answer
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
    //keep searching for the right node based on BST structure
    else if (current->getValue() > i)
    {
        return (left(current->getLeftSon(), i));
    }
    else
    {
        return (left(current->getRightSon(), i));
    }
}

//right private supporting method
int ariel::Tree::right(TreeNode *current, int i)
{
    //if this current node has the value we're looking for - > check if it has a right son and return the answer
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
    //keep searching for the right node based on BST structure
    else if (current->getValue() > i)
    {
        return (right(current->getLeftSon(), i));
    }
    else
    {
        return (right(current->getRightSon(), i));
    }
}

//print private supporting method
void ariel::Tree::print(TreeNode *current)
{
    /* first recur on left child */
    if (current == nullptr)
        return;
    print(current->getLeftSon());
    /* then print the data of node */
    std::cout << current->getValue() << " ";
    /* now recur on right child */
    print(current->getRightSon());
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
            this->_sizeOfTree--;
            return;
        }
        //in case the asked-to remove node has ONLY left son - > we'll push this son instead of the node
        else if (((current->getLeftSon() != nullptr) && (current->getRightSon() == nullptr)))
        {
            *current = *(current->getLeftSon());
            this->_sizeOfTree--;
            return;
        }
        //in case the asked-to remove node has ONLY right son - > we'll push this son instead of the node
        else if (((current->getLeftSon() == nullptr) && (current->getRightSon() != nullptr)))
        {

            *current = *(current->getRightSon());
            this->_sizeOfTree--;
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
                this->_sizeOfTree--;
                return;
            }
            else
            {
                current->setValue(tempOfMinFromRight->getValue());
                parentOfMin->setLeftSon(nullptr);
                this->_sizeOfTree--;
                return;
            }
        }
    }
    //keep searching for the right node based on BST structure
    else if (current->getValue() > i)
    {
        remove(current->getLeftSon(), i);
    }
    else if (current->getValue() < i)
    {
        remove(current->getRightSon(), i);
    }
}

//private supporting method to "help" remove method in case both children exist - >
//finding the smallest valued node in given sub tree
TreeNode *ariel::Tree::findMin(TreeNode *current)
{
    //if there is no more
    if (current->getLeftSon() == nullptr)
    {
        return (current);
    }
    else
    {
        return (ariel::Tree::findMin(current->getLeftSon()));
    }
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

//private supporting method to "help" the remove method - >  find certain node's parent and return the pointer to it
TreeNode *ariel::Tree::findParent(TreeNode *current, int i)
{
    if (current == nullptr)
    {
        throw std::invalid_argument("no such node NULLPTR");
    }
    else if ((current->getLeftSon() == nullptr) && (current->getRightSon() == nullptr))
    {
        throw std::invalid_argument("no such node NULLSONS");
    }
    else if ((current->getLeftSon() != nullptr && current->getLeftSon()->getValue() == i) || (current->getRightSon() != nullptr && current->getRightSon()->getValue() == i))
    {
        return current;
    }
    if (current->getValue() > i)
        return ariel::Tree::findParent(current->getLeftSon(), i);

    else
        return ariel::Tree::findParent(current->getRightSon(), i);
}

//private method to return if given tree is empty
bool ariel::Tree::isEmpty()
{
    return (this->_sizeOfTree == 0);
}
