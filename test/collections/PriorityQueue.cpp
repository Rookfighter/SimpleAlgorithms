#include <UnitTest++.h>
#include <stdexcept>
#include "collections/PriorityQueue.hpp"

struct PriorityQueueFixture {
    sa::PriorityQueue testQueue;

    PriorityQueueFixture()
    {

    }

    ~PriorityQueueFixture()
    {
        testQueue.clear();
    }
};

SUITE(priority_queue)
{
    TEST_FIXTURE(PriorityQueueFixture, pop_empty)
    {
        CHECK(testQueue.empty());
        CHECK_THROW(testQueue.pop(), std::logic_error);
    }

    TEST_FIXTURE(PriorityQueueFixture, insert_unsorted)
    {
        testQueue.insert(3);
        testQueue.insert(2);
        testQueue.insert(4);
        testQueue.insert(1);
        testQueue.insert(0);

        CHECK_EQUAL(4, testQueue.pop());
        CHECK_EQUAL(3, testQueue.pop());
        CHECK_EQUAL(2, testQueue.pop());
        CHECK_EQUAL(1, testQueue.pop());
        CHECK_EQUAL(0, testQueue.pop());

        CHECK(testQueue.empty());
    }

    TEST_FIXTURE(PriorityQueueFixture, insert_sorted)
    {
        int numsToTest = 5;
        for(int i = 0; i < numsToTest; ++i)
            testQueue.insert(i);

        for(int i = numsToTest - 1; i >= 0; --i)
            CHECK_EQUAL(i, testQueue.pop());

        CHECK(testQueue.empty());
    }
}
