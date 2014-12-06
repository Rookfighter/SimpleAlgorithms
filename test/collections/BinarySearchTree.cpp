#include <UnitTest++.h>
#include "collections/BinarySearchTree.hpp"

struct BinTreeFixture {
    sa::BinarySearchTree testTree;

    BinTreeFixture()
    {

    }

    ~BinTreeFixture()
    {

    }
};

SUITE(binary_search_tree)
{
    TEST_FIXTURE(BinTreeFixture, remove_empty)
    {
        CHECK(testTree.empty());
        testTree.remove(1);
    }

    TEST_FIXTURE(BinTreeFixture, contains_empty)
    {
        CHECK(testTree.empty());
        testTree.contains(1);
    }

    TEST_FIXTURE(BinTreeFixture, clear_empty)
    {
        CHECK(testTree.empty());
        testTree.clear();
    }

    TEST_FIXTURE(BinTreeFixture, insert_unsorted)
    {
        testTree.insert(3);
        testTree.insert(0);
        testTree.insert(4);
        testTree.insert(2);
        testTree.insert(1);

        CHECK(!testTree.empty());
        CHECK_EQUAL(5, testTree.size());

        CHECK(testTree.contains(0));
        CHECK(testTree.contains(1));
        CHECK(testTree.contains(2));
        CHECK(testTree.contains(3));
        CHECK(testTree.contains(4));
        CHECK(!testTree.contains(5));

        testTree.remove(2);
        testTree.remove(0);
        testTree.remove(4);

        CHECK(!testTree.empty());
        CHECK_EQUAL(2, testTree.size());

        CHECK(testTree.contains(1));
        CHECK(testTree.contains(3));

        testTree.clear();
        CHECK(testTree.empty());
    }

    TEST_FIXTURE(BinTreeFixture, insert_sorted)
    {
        testTree.insert(0);
        testTree.insert(1);
        testTree.insert(2);
        testTree.insert(3);
        testTree.insert(4);

        CHECK(!testTree.empty());
        CHECK_EQUAL(5, testTree.size());

        CHECK(testTree.contains(0));
        CHECK(testTree.contains(1));
        CHECK(testTree.contains(2));
        CHECK(testTree.contains(3));
        CHECK(testTree.contains(4));
        CHECK(!testTree.contains(5));

        testTree.remove(2);
        testTree.remove(0);
        testTree.remove(4);

        CHECK(!testTree.empty());
        CHECK_EQUAL(2, testTree.size());

        CHECK(testTree.contains(1));
        CHECK(testTree.contains(3));

        testTree.clear();
        CHECK(testTree.empty());
    }

    TEST_FIXTURE(BinTreeFixture, insert_duplicate)
    {
        testTree.insert(0);
        testTree.insert(1);
        testTree.insert(1);
        testTree.insert(1);
        testTree.insert(0);

        CHECK(!testTree.empty());
        CHECK_EQUAL(2, testTree.size());

        CHECK(testTree.contains(0));
        CHECK(testTree.contains(1));

        testTree.clear();
        CHECK(testTree.empty());
    }

    TEST_FIXTURE(BinTreeFixture, memory_leak)
    {
        testTree.insert(0);
        testTree.insert(1);
        testTree.insert(2);
        testTree.insert(1);
        testTree.remove(2);
        // check for memory leaks e.g. with valgrind
    }
}
