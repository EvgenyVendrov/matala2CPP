#include "TreeNode.hpp"
namespace ariel
{
class Tree
{
  TreeNode *_root;

public:
  Tree();
  Tree(TreeNode root);
  void insert(int i);
  //void remove(int i);
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
  int size(TreeNode* current);
  int parent(TreeNode* current, int i);
  int left(TreeNode* current, int i);
  int right (TreeNode* current, int i);
  void print (TreeNode* current);
};
} // namespace ariel