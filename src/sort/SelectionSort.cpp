#include "sort/sort.hpp"

namespace sa
{
	void selectionSort(std::vector<int> &p_toSort)
	{
		if(p_toSort.empty())
			return;

		for(unsigned int i = 0; i < p_toSort.size() - 1; ++i) {
			unsigned int min = i;
			for(unsigned int j = i + 1; j < p_toSort.size(); ++j) {
				if(p_toSort[j] < p_toSort[min])
					min = j;
			}

			if(min != i) {
				int value = p_toSort[i];
				p_toSort[i] =p_toSort[min];
				p_toSort[min] = value;
			}
		}
	}
}
