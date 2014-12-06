#ifndef TEST_SORT_SORTFIXTURES_HPP_
#define TEST_SORT_SORTFIXTURES_HPP_

#include <vector>

struct UniqueListFixture
{
    // contains only unique elements
    std::vector<int> testData;
    const std::vector<int> testResult = { 0, 1, 2, 3, 4 };

    UniqueListFixture()
    {
        testData.resize(5);
        testData[0] = 4;
        testData[1] = 1;
        testData[2] = 3;
        testData[3] = 0;
        testData[4] = 2;
    }

    ~UniqueListFixture()
    {
    }
};

struct DuplicateListFixture
{
    // also contains duplicate elements
    std::vector<int> testData;
    const std::vector<int> testResult = {2, 2, 5, 5, 5};

    DuplicateListFixture()
    {
        testData.resize(5);
        testData[0] = 2;
        testData[1] = 5;
        testData[2] = 5;
        testData[3] = 5;
        testData[4] = 2;

    }

    ~DuplicateListFixture()
    {
    }
};

struct SortedListFixture
{
    // contains negative and positive elements
    std::vector<int> testData;
    const std::vector<int> testResult = { 4, 5, 6, 7, 8 };

    SortedListFixture()
    {
        testData = testResult;
    }

    ~SortedListFixture()
    {

    }
};

struct SingleListFixture
{
    // contains only 1 element
    std::vector<int> testData;
    const std::vector<int> testResult = { 1 };

    SingleListFixture()
    {
        testData.resize(1);
        testData[0] = 1;
    }

    ~SingleListFixture()
    {
    }
};

struct EmptyListFixture
{
    // contains no element
    std::vector<int> emptyList;

    EmptyListFixture()
    {
        emptyList.clear();
    }

    ~EmptyListFixture()
    {
    }
};

#endif
