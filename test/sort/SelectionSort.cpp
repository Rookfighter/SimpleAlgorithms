#include <UnitTest++.h>
#include "sort/sort.hpp"
#include "SortFixtures.hpp"
#include "CheckMacros.hpp"

SUITE(selection_sort)
{
    TEST_FIXTURE(UniqueElementsFixture, unique_elements)
    {
        sa::selectionSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(DuplicateElementsFixture, duplicate_elements)
    {
        sa::selectionSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(NegativeElementsFixture, negative_elements)
    {
        sa::selectionSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(SingleElementFixture, duplicate_elements)
    {
        sa::selectionSort(testData);
        CHECK_VECTOR_EQUAL(testResult, testData);
    }

    TEST_FIXTURE(EmptyListFixture, empty_list)
    {
        sa::selectionSort(emptyList);
        CHECK(emptyList.empty());
    }
}
