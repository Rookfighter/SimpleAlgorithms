#include <UnitTest++.h>
#include "sort/sort.hpp"
#include "SortFixtures.hpp"
#include "CheckMacros.hpp"

SUITE(heap_sort)
{
    TEST_FIXTURE(UniqueListFixture, unique_list)
    {
        sa::heapSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(DuplicateListFixture, duplicate_list)
    {
        sa::heapSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(SortedListFixture, sorted_list)
    {
        sa::heapSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(SingleListFixture, single_list)
    {
        sa::heapSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(EmptyListFixture, empty_list)
    {
        sa::heapSort(emptyList);
        CHECK(emptyList.empty());
    }
}
