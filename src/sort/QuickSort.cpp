#include "sort/sort.hpp"

namespace sa
{
	static int partition(std::vector<int> &p_toSort, const int p_left, const int p_right)
	{
		int pivot = p_toSort[p_right];
		int i = p_left - 1;
		int j = p_right;

		while(true) {
			do ++i; while(p_toSort[i] < pivot);
			do --j; while(j > i && p_toSort[j] > pivot);

			if(j <= i) {
				// all smaller elementes moved to left
				// and all bigger elements moved to right
				break;
			}

			int tmp = p_toSort[i];
			p_toSort[i] = p_toSort[j];
			p_toSort[j] = tmp;
		}

		p_toSort[p_right] = p_toSort[i];
		p_toSort[i] = pivot;

		return i;
	}

	static void quickSort(std::vector<int> &p_toSort, const int p_left, const int p_right)
	{
		if(p_right > p_left) {
			int mid = partition(p_toSort, p_left, p_right);

			quickSort(p_toSort, p_left, mid - 1);
			quickSort(p_toSort, mid + 1, p_right);
		}
	}

	void quickSort(std::vector<int> &p_toSort)
	{
		quickSort(p_toSort, 0, p_toSort.size() - 1);
	}


}
