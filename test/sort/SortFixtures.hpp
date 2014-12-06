#ifndef TEST_SORT_SORTFIXTURES_HPP_
#define TEST_SORT_SORTFIXTURES_HPP_

#include <vector>

struct UniqueElementsFixture
{
    // contains only unique elements
    std::vector<int> testData;
    const std::vector<int> testResult = { 0, 1, 3, 4, 5, 7, 9 };

    UniqueElementsFixture()
    {
        testData.resize(7);
        testData[0] = 5;
        testData[1] = 1;
        testData[2] = 4;
        testData[3] = 0;
        testData[4] = 9;
        testData[5] = 3;
        testData[6] = 7;
    }

    ~UniqueElementsFixture()
    {
    }
};

struct DuplicateElementsFixture
{
    // also contains duplicate elements
    std::vector<int> testData;
    const std::vector<int> testResult = { 2, 3, 3, 4, 4, 7, 7, 7, 11, 11 };

    DuplicateElementsFixture()
    {
        testData.resize(10);
        testData[0] = 7;
        testData[1] = 3;
        testData[2] = 11;
        testData[3] = 2;
        testData[4] = 7;
        testData[5] = 4;
        testData[6] = 4;
        testData[7] = 3;
        testData[8] = 11;
        testData[9] = 7;
    }

    ~DuplicateElementsFixture()
    {
    }
};

struct NegativeElementsFixture
{
    // contains negative and positive elements
    std::vector<int> testData;
    const std::vector<int> testResult = { -5, -2, -1, 2, 4, 7, 8 };

    NegativeElementsFixture()
    {
        testData.resize(7);
        testData[0] = 8;
        testData[1] = -2;
        testData[2] = -1;
        testData[3] = 7;
        testData[4] = -5;
        testData[5] = 2;
        testData[6] = 4;
    }

    ~NegativeElementsFixture()
    {

    }
};

struct SingleElementFixture
{
    // contains only 1 element
    std::vector<int> testData;
    const std::vector<int> testResult = { 1 };

    SingleElementFixture()
    {
        testData.resize(1);
        testData[0] = 1;
    }

    ~SingleElementFixture()
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
