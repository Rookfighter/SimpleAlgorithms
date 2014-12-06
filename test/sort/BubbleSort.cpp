#include <UnitTest++.h>
#include "sort/sort.hpp"
#include "SortFixtures.hpp"
#include "CheckMacros.hpp"

SUITE(bubble_sort)
{
    TEST_FIXTURE(UniqueListFixture, unique_list)
    {
        sa::bubbleSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(DuplicateListFixture, duplicate_list)
    {
        sa::bubbleSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(SortedListFixture, sorted_list)
    {
        sa::bubbleSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(SingleListFixture, single_list)
    {
        sa::bubbleSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(EmptyListFixture, empty_list)
    {
        sa::bubbleSort(emptyList);
        CHECK(emptyList.empty());
    }
}
