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
namespace evgeny
{
bool isIn(int arr[], int number, int lengthOfArr)
{
    for (int i = 0; i <= lengthOfArr; i++)
    {
        if (arr[i] == number)
            return true;
    }
    return false;
}
} // namespace evgeny

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
    //////////////////////////***********my own - new tests***********//////////////////////////

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
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ariel::Tree testingRemove;
    //as the remove method is the one with most case's to handle
    //we created a tree sized 20 random nodes (rand in my architecture is from 0 to 2147483647)
    //then - we'll remove them all in a random order one by one - to promise that we cover as much "remove cases" as possible
    int insertArr[20];
    int randNum = 0;
    for (int i = 0; i < 20; i++)
    {
        randNum = rand();
        while (evgeny::isIn(insertArr, randNum, i))
        {
            randNum = rand();
        }
        insertArr[i] = randNum;
        testingRemove.insert(insertArr[i]);
    }
    badkan::TestCase tc3("full remove test");
    tc3
    .CHECK_EQUAL(testingRemove.size(), 20)
    .CHECK_EQUAL(testingRemove.contains(insertArr[0]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[1]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[2]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[3]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[4]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[5]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[6]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[7]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[8]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[9]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[10]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[11]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[12]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[13]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[14]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[15]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[16]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[17]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[18]), true)
    .CHECK_EQUAL(testingRemove.contains(insertArr[19]), true)
    /////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[7]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[7]), false)
    .CHECK_EQUAL(testingRemove.size(), 19)
    //////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[0]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[0]), false)
    .CHECK_EQUAL(testingRemove.size(), 18)
    /////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[16]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[16]), false)
    .CHECK_EQUAL(testingRemove.size(), 17)
    /////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[10]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[10]), false)
    .CHECK_EQUAL(testingRemove.size(), 16)
    //////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[3]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[3]), false)
    .CHECK_EQUAL(testingRemove.size(), 15)
    //////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[9]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[9]), false)
    .CHECK_EQUAL(testingRemove.size(), 14)
    //////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[19]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[19]), false)
    .CHECK_EQUAL(testingRemove.size(), 13)
    /////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[1]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[1]), false)
    .CHECK_EQUAL(testingRemove.size(), 12)
    //////////////////////////////////////////////////////
    //tyring to remove a node already removed - > to check if the method will throw exception
    .CHECK_THROWS(testingRemove.remove(insertArr[19]))
    /////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[17]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[17]), false)
    .CHECK_EQUAL(testingRemove.size(), 11)
    ////////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[5]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[5]), false)
    .CHECK_EQUAL(testingRemove.size(), 10)
    // ///////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[13]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[13]), false)
    .CHECK_EQUAL(testingRemove.size(), 9)
    //////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[15]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[15]), false)
    .CHECK_EQUAL(testingRemove.size(), 8)
    //////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[2]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[2]), false)
    .CHECK_EQUAL(testingRemove.size(), 7)
    //////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[18]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[18]), false)
    .CHECK_EQUAL(testingRemove.size(), 6)
    //////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[12]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[12]), false)
    .CHECK_EQUAL(testingRemove.size(), 5)
    //////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[11]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[11]), false)
    .CHECK_EQUAL(testingRemove.size(), 4)
    //////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[4]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[4]), false)
    .CHECK_EQUAL(testingRemove.size(), 3)
    //////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[14]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[14]), false)
    .CHECK_EQUAL(testingRemove.size(), 2)
    //////////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[8]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[8]), false)
    .CHECK_EQUAL(testingRemove.size(), 1)
    ///////////////////////////////////////////////
    .CHECK_OK(testingRemove.remove(insertArr[6]))
    .CHECK_EQUAL(testingRemove.contains(insertArr[6]), false)
    .CHECK_EQUAL(testingRemove.size(), 0)
    ///////////////////////////////////////////////
    .print();

    cout
            << "for full remove testing tree - >"
            << "You have " << tc3.right() << " right answers and " << tc3.wrong() << " wrong answers so your grade is " << tc3.grade() << ". Great!" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ariel::Tree testingTree;
    //filling the tree with the values  1 - > 8 - > 3 - > 64 - > 5 - > 216 - > 7 - > 512 - > 9 (by the order written)
    //then checking whether tree's structure is maintained after all the inserts and removals - based on the algorithem listed here:
    //http://www.algolist.net/Data_structures/Binary_search_tree/Removal
    for (int i = 1; i <= 9; i++)
    {
        if (i % 2 == 0)
        {
            testingTree.insert(i * i * i);
        }
        else
        {
            testingTree.insert(i);
        }
    }
    badkan::TestCase tc4("left-right-parent test");
    tc4
    //making sure the root has no parent
    .CHECK_THROWS(testingTree.parent(1))
    //making sure the lower nodes, i.e. "leafs" have no children
    .CHECK_THROWS(testingTree.left(512))
    .CHECK_THROWS(testingTree.right(512))
    .CHECK_THROWS(testingTree.left(9))
    .CHECK_THROWS(testingTree.right(9))
    .CHECK_THROWS(testingTree.left(7))
    .CHECK_THROWS(testingTree.right(7))
    //checking that the structure is similar to the one i got from usfca simulator
    .CHECK_THROWS(testingTree.left(3))
    .CHECK_THROWS(testingTree.left(5))
    .CHECK_THROWS(testingTree.left(1))
    .CHECK_THROWS(testingTree.left(216))
    .CHECK_EQUAL(testingTree.right(1), 8)
    .CHECK_EQUAL(testingTree.right(8), 64)
    .CHECK_EQUAL(testingTree.left(8), 3)
    .CHECK_EQUAL(testingTree.right(64), 216)
    .CHECK_EQUAL(testingTree.left(64), 9)
    .CHECK_EQUAL(testingTree.right(216), 512)
    .CHECK_EQUAL(testingTree.right(3), 5)
    .CHECK_EQUAL(testingTree.right(5), 7)
    //checking that for a non - exsitent node we'll get exception
    .CHECK_THROWS(testingTree.right(777))
    .CHECK_THROWS(testingTree.parent(777))
    .CHECK_THROWS(testingTree.left(777))
    //now removing 64 - to check whether the structure maintained after removal
    .CHECK_OK(testingTree.remove(64))
    .CHECK_EQUAL(testingTree.size(), 8)
    .CHECK_EQUAL(testingTree.contains(64), false)
    .CHECK_EQUAL(testingTree.contains(1), true)
    .CHECK_EQUAL(testingTree.contains(8), true)
    .CHECK_EQUAL(testingTree.contains(3), true)
    .CHECK_EQUAL(testingTree.contains(5), true)
    .CHECK_EQUAL(testingTree.contains(216), true)
    .CHECK_EQUAL(testingTree.contains(7), true)
    .CHECK_EQUAL(testingTree.contains(512), true)
    .CHECK_EQUAL(testingTree.contains(9), true)
    //now checking tree's structure
    .CHECK_EQUAL(testingTree.root(), 1)
    .CHECK_EQUAL(testingTree.right(1), 8)
    .CHECK_EQUAL(testingTree.right(8), 216)
    .CHECK_EQUAL(testingTree.right(216), 512)
    .CHECK_EQUAL(testingTree.left(216), 9)
    .CHECK_EQUAL(testingTree.left(8), 3)
    .CHECK_EQUAL(testingTree.right(3), 5)
    .CHECK_EQUAL(testingTree.right(5), 7)
    //now removing 8
    .CHECK_OK(testingTree.remove(8))
    .CHECK_EQUAL(testingTree.size(), 7)
    .CHECK_EQUAL(testingTree.contains(64), false)
    .CHECK_EQUAL(testingTree.contains(1), true)
    .CHECK_EQUAL(testingTree.contains(8), false)
    .CHECK_EQUAL(testingTree.contains(3), true)
    .CHECK_EQUAL(testingTree.contains(5), true)
    .CHECK_EQUAL(testingTree.contains(216), true)
    .CHECK_EQUAL(testingTree.contains(7), true)
    .CHECK_EQUAL(testingTree.contains(512), true)
    .CHECK_EQUAL(testingTree.contains(9), true)
    //now checking tree's structure
    .CHECK_EQUAL(testingTree.root(), 1)
    .CHECK_EQUAL(testingTree.right(1), 9)
    .CHECK_EQUAL(testingTree.right(9), 216)
    .CHECK_EQUAL(testingTree.right(216), 512)
    .CHECK_EQUAL(testingTree.left(9), 3)
    .CHECK_EQUAL(testingTree.right(3), 5)
    .CHECK_EQUAL(testingTree.right(5), 7)
    .print();
    cout << "in left-right-parent tests - >"
         << "You have " << tc4.right() << " right answers and " << tc4.wrong() << " wrong answers so your grade is " << tc4.grade() << ". Great!" << endl;
}
