/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <cstdlib>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main()
{
  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  badkan::TestCase tc("Binary tree");
  tc
      .CHECK_EQUAL(emptytree.size(), 0)
      .CHECK_OK(emptytree.insert(5))
      .CHECK_EQUAL(emptytree.size(), 1)
      .CHECK_EQUAL(emptytree.contains(5), true)
      .CHECK_OK(emptytree.remove(5))
      .CHECK_THROWS(emptytree.remove(5))
      .CHECK_EQUAL(emptytree.size(), 0)

      .CHECK_EQUAL(threetree.size(), 3)
      .CHECK_EQUAL(threetree.root(), 5)
      .CHECK_EQUAL(threetree.parent(3), 5)
      .CHECK_EQUAL(threetree.parent(7), 5)
      .CHECK_EQUAL(threetree.left(5), 3)
      .CHECK_EQUAL(threetree.right(5), 7)
      .CHECK_THROWS(threetree.insert(3))
      .CHECK_OK(threetree.print())

      .print();
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
  //my own - new tests:
  ariel::Tree emptytree2;
  //testing all the methods on an empty tree
  badkan::TestCase tc2("empty tree test");
  tc2
      .CHECK_THROWS(emptytree2.remove(1))
      .CHECK_EQUAL(emptytree2.size(), 0)
      .CHECK_EQUAL(emptytree2.contains(6), false)
      .CHECK_THROWS(emptytree2.root())
      .CHECK_THROWS(emptytree2.left(5))
      .CHECK_THROWS(emptytree2.right(3))
      .CHECK_THROWS(emptytree2.parent(7))
      .CHECK_OK(emptytree2.print())
      .print();

  cout << "in empty-tree tests - >"
       << "You have " << tc2.right() << " right answers and " << tc2.wrong() << " wrong answers so your grade is " << tc2.grade() << ". Great!" << endl;
  ////////////////////////////////////////////////////////
  ariel::Tree testingTree;
  int insertArr[20];
  for (int i = 0; i < 20; i++)
  {
    insertArr[i] = rand();
    testingTree.insert(insertArr[i]);
  }
  badkan::TestCase tc3("detailed full tree test");
  tc3
      .CHECK_EQUAL(testingTree.size(), 20)
      .CHECK_EQUAL(testingTree.contains(insertArr[0]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[1]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[2]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[3]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[4]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[5]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[6]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[7]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[8]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[9]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[10]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[11]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[12]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[13]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[14]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[15]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[16]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[17]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[18]), true)
      .CHECK_EQUAL(testingTree.contains(insertArr[19]), true)
      .CHECK_OK(testingTree.remove(insertArr[7]))
      .CHECK_EQUAL(testingTree.contains(insertArr[7]), false)
      .CHECK_EQUAL(testingTree.size(), 19)
      .CHECK_OK(testingTree.remove(insertArr[0]))
      .CHECK_EQUAL(testingTree.contains(insertArr[0]), false)
      .CHECK_EQUAL(testingTree.size(), 18)
      .CHECK_OK(testingTree.remove(insertArr[16]))
      .CHECK_EQUAL(testingTree.contains(insertArr[16]), false)
      .CHECK_EQUAL(testingTree.size(), 17)
      .CHECK_OK(testingTree.remove(insertArr[10]))
      .CHECK_EQUAL(testingTree.contains(insertArr[10]), false)
      .CHECK_EQUAL(testingTree.size(), 16)
      .print();

  cout
      << "for testing tree - >"
      << "You have " << tc3.right() << " right answers and " << tc3.wrong() << " wrong answers so your grade is " << tc3.grade() << ". Great!" << endl;
}
