#ifndef TEST_UTILS_CHECKMACROS_HPP_
#define TEST_UTILS_CHECKMACROS_HPP_

#include <UnitTest++.h>

#define CHECK_VECTOR_EQUAL(expected, actual) \
	CHECK_EQUAL(expected.size(), actual.size()); \
	CHECK_ARRAY_EQUAL(expected.data(), actual.data(), expected.size())

#endif
