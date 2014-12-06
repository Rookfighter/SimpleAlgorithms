#include <UnitTest++.h>
#include <stdexcept>
#include "collections/HashDictionary.hpp"

struct HashDictFixture
{
    sa::HashDictionary testDict;

    HashDictFixture()
    {

    }

    ~HashDictFixture()
    {

    }
};

SUITE(hash_dictionary)
{
    TEST_FIXTURE(HashDictFixture, remove_empty)
    {
        CHECK(testDict.empty());
        testDict.remove(1);
    }

    TEST_FIXTURE(HashDictFixture, get_empty)
    {
        CHECK(testDict.empty());
        CHECK_THROW(testDict.get(1), std::logic_error);
    }

    TEST_FIXTURE(HashDictFixture, contains_empty)
    {
        CHECK(testDict.empty());
        CHECK(!testDict.contains(1));
    }

    TEST_FIXTURE(HashDictFixture, clear_empty)
    {
        CHECK(testDict.empty());
        testDict.clear();
    }

    TEST_FIXTURE(HashDictFixture, insert_unsorted)
    {
        testDict.insert(1, 11);
        testDict.insert(3, 13);
        testDict.insert(0, 10);
        testDict.insert(4, 14);
        testDict.insert(2, 12);

        CHECK(!testDict.empty());
        CHECK_EQUAL(5, testDict.size());

        CHECK(testDict.contains(0));
        CHECK(testDict.contains(1));
        CHECK(testDict.contains(2));
        CHECK(testDict.contains(3));
        CHECK(testDict.contains(4));

        CHECK_EQUAL(10, testDict.get(0));
        CHECK_EQUAL(11, testDict.get(1));
        CHECK_EQUAL(12, testDict.get(2));
        CHECK_EQUAL(13, testDict.get(3));
        CHECK_EQUAL(14, testDict.get(4));

        testDict.remove(3);
        testDict.remove(0);
        testDict.remove(2);

        CHECK_EQUAL(2, testDict.size());

        CHECK(testDict.contains(1));
        CHECK(testDict.contains(4));

        CHECK_EQUAL(11, testDict.get(1));
        CHECK_EQUAL(14, testDict.get(4));

        testDict.clear();
        CHECK(testDict.empty());
    }

    TEST_FIXTURE(HashDictFixture, insert_sorted)
    {
        testDict.insert(0, 10);
        testDict.insert(1, 11);
        testDict.insert(2, 12);
        testDict.insert(3, 13);
        testDict.insert(4, 14);

        CHECK(!testDict.empty());
        CHECK_EQUAL(5, testDict.size());

        CHECK(testDict.contains(0));
        CHECK(testDict.contains(1));
        CHECK(testDict.contains(2));
        CHECK(testDict.contains(3));
        CHECK(testDict.contains(4));

        CHECK_EQUAL(10, testDict.get(0));
        CHECK_EQUAL(11, testDict.get(1));
        CHECK_EQUAL(12, testDict.get(2));
        CHECK_EQUAL(13, testDict.get(3));
        CHECK_EQUAL(14, testDict.get(4));

        testDict.remove(3);
        testDict.remove(0);
        testDict.remove(2);

        CHECK_EQUAL(2, testDict.size());

        CHECK(testDict.contains(1));
        CHECK(testDict.contains(4));

        CHECK_EQUAL(11, testDict.get(1));
        CHECK_EQUAL(14, testDict.get(4));

        testDict.clear();
        CHECK(testDict.empty());
    }

    TEST_FIXTURE(HashDictFixture, insert_duplicate)
    {
        testDict.insert(1, 11);
        testDict.insert(3, 13);
        testDict.insert(3, 23);
        testDict.insert(3, 33);
        testDict.insert(1, 21);

        CHECK(!testDict.empty());
        CHECK_EQUAL(2, testDict.size());

        CHECK(testDict.contains(1));
        CHECK(testDict.contains(3));

        CHECK_EQUAL(21, testDict.get(1));
        CHECK_EQUAL(33, testDict.get(3));

        testDict.clear();
        CHECK(testDict.empty());
    }

    TEST_FIXTURE(HashDictFixture, memory_leak)
    {
        testDict.insert(1, 11);
        testDict.insert(2, 12);
        testDict.insert(3, 13);
        testDict.insert(1, 21);
        testDict.remove(2);
        // check for memory leaks e.g. with valgrind
    }

}
