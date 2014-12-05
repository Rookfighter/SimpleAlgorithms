#ifndef SRC_SORT_SORT_HPP_
#define SRC_SORT_SORT_HPP_

#include <vector>

namespace sa
{
	void bubbleSort(std::vector<int> &p_toSort);
	void insertionSort(std::vector<int> &p_toSort);
	void selectionSort(std::vector<int> &p_toSort);
	void quickSort(std::vector<int> &p_toSort);
	void mergeSort(std::vector<int> &p_toSort);
	void heapSort(std::vector<int> &p_toSort);
}

#endif
