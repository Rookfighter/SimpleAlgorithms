cmake_minimum_required (VERSION 2.8)
project(SimpleAlgorithms)

SET(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")

get_filename_component(UNITTEST++_ROOT "lib/UnitTest++" ABSOLUTE)
find_package(UnitTest++)

include_directories("src")
file(GLOB ALGORITHMS_SRC
	 "src/sort/*.cpp")

add_library(${PROJECT_NAME} ${ALGORITHMS_SRC})

include_directories(${UNITTEST++_INCLUDE_DIRS}
	"test/utils"
	"test/sort")
set(TEST_BIN_NAME "Test${PROJECT_NAME}")
file(GLOB TEST_SRC
	"test/main.cpp"
	"test/sort/*.cpp"
	"test/utils/*.cpp")
add_executable(${TEST_BIN_NAME} ${TEST_SRC})
target_link_libraries(${TEST_BIN_NAME} ${UNITTEST++_LIBRARIES} ${PROJECT_NAME})

add_custom_target(test ./${TEST_BIN_NAME}
    DEPENDS ./${TEST_BIN_NAME})
