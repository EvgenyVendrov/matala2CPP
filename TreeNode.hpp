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
    TreeNode* getRightSon();
    TreeNode* getLeftSon();
};
