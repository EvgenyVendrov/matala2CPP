#include <iostream>
#include <string>
//**********Tree Node class**********
class TreeNode
{
  int _value;
  TreeNode *_rightSon;
  TreeNode *_leftSon;

public:
  //constructors
  TreeNode();
  TreeNode(const int value, const TreeNode rightSon, const TreeNode leftSon);
  TreeNode(const int value);
  //printing method to "help" the Tree method
  void print() const;
  //setters
  void setValue(const int value);
  void setRightSon(TreeNode *const rightSon);
  void setLeftSon(TreeNode *const leftSon);
  //getters
  int getValue() const;
  TreeNode *getRightSon() const;
  TreeNode *getLeftSon() const;
};
///////////////////////////////////////////////////
//**********Tree class(found in "ariel" name space as demanded)**********
namespace ariel
{
class Tree
{
  TreeNode *_root;

public:
  Tree();
  ~Tree();
  void insert(const int i);
  void remove(const int i);
  int size() const;
  bool contains(const int i) const;
  int root() const;
  int parent(const int i) const;
  int left(const int i) const;
  int right(const int i) const;
  void print() const;

private:
  void insert(TreeNode *current, const int i);
  void remove(TreeNode *current, const int i);
  bool contains(TreeNode *current, const int i) const;
  int parent(TreeNode *current, const int i) const;
  int left(TreeNode *current, const int i) const;
  int right(TreeNode *current, const int i) const;
  void print(TreeNode *current) const;
  void destroyTree(TreeNode *current);
  TreeNode *findMin(TreeNode *current) const;
  TreeNode *findParent(TreeNode *current, const int i) const;
  bool isEmpty() const;
  int _sizeOfTree;
};
} // namespace ariel