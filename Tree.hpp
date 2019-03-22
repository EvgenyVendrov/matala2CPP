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
    TreeNode(int value, TreeNode rightSon, TreeNode leftSon);
    TreeNode(int value);
    void print();
    //setters
    void setValue(int value);
    void setRightSon(TreeNode *rightSon);
    void setLeftSon(TreeNode *leftSon);
    //getters
    int getValue();
    TreeNode *getRightSon();
    TreeNode *getLeftSon();
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
    void insert(int i);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();

  private:
    void insert(TreeNode *current, int i);
    bool contains(TreeNode *current, int i);
    int size(TreeNode *current);
    int parent(TreeNode *current, int i);
    int left(TreeNode *current, int i);
    int right(TreeNode *current, int i);
    void print(TreeNode *current);
    void remove(TreeNode *current, int i);
    void destroyTree(TreeNode *current);
    TreeNode *findMin(TreeNode *current);
    TreeNode *findParent(TreeNode *current, int i);
    bool isEmpty();
    int _sizeOfTree;
};
} // namespace ariel