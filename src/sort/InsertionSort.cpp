#include "sort/sort.hpp"

namespace sa
{
	void insertionSort(std::vector<int> &p_toSort)
	{
		for(unsigned int i = 1; i < p_toSort.size(); ++i) {
			int value = p_toSort[i];
			unsigned int j = i;
			while(j > 0 && p_toSort[j-1] > value) {
				p_toSort[j] = p_toSort[j-1];
				--j;
			}

			p_toSort[j] = value;
		}
	}
}
