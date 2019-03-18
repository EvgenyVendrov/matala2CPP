#include <iostream>
#include "TreeNode.hpp"
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

TreeNode* TreeNode::getLeftSon()
{
    return (this->_leftSon);
}

TreeNode* TreeNode::getRightSon()
{
    return (this->_rightSon);
}

void TreeNode::print(){
    std::cout<<(this->getValue())<<"  ";
}
