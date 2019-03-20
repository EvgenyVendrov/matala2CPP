/**
 * Demo program for the exercise on binary trees
 *
 * @author Erel Segal-Halevi
 * 
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;

#include "Tree.hpp"

int main()
{
  try
  {
    // constructs an empty tree:
    ariel::Tree emptytree;
    cout << "emptytree: size=" << emptytree.size() << endl; // should print 0

    // constructs an ordered binary tree where:
    // 5 is in the root;
    // 3 is the root's left child;
    // 7 is the root's right child.
    ariel::Tree threetree;
    threetree.insert(5);
    threetree.insert(7);
    threetree.insert(3);
    cout << "threetree: size=" << threetree.size() << " root=" << threetree.root() << endl
         << "   "; // size=3, root=5.
    threetree.print();
    cout << endl;

    cout << threetree.size()    // should print 3
         << threetree.parent(3) // should print 5
         << threetree.parent(7) // should print 5
         << threetree.left(5)   // should print 3
         << threetree.right(5)  // should print 7
         << endl;
    //threetree.insert(5);    // should throw an exception, since 5 already exists.
    threetree.remove(5);
    threetree.print();
    cout << threetree.root();
    //threetree.remove(5);
    ariel::Tree testingTree;
    int insertArr[10]={3,44,5,66,71,99,2,9,22,1};
    for (int i = 0; i <= 9; i++)
    {
      testingTree.insert(insertArr[i]);
    }
    cout << "SIZEEEEE->" << (testingTree.size())<<endl;
    cout<<"PRINT=>"<<endl;
    testingTree.print();
    cout<<"ROOT=>"<<testingTree.root();
    cout<<"LOOKING FOR=>"<<insertArr[7]<<endl;
    cout <<"PARENT OF "<<insertArr[7]<<"IS "<<testingTree.parent(insertArr[7])<<endl;
    testingTree.remove(66);
    cout << "FINAL SIZE->" << (testingTree.size());
    testingTree.print();
  }
  catch (const std::exception &exc)
  {
    std::cerr << exc.what();
  }
}