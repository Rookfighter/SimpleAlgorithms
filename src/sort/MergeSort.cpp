#include "sort/sort.hpp"

namespace sa
{
	static void copy(const std::vector<int> &p_src, const int p_startSrc, std::vector<int> &p_dest, const int p_startDest, const int p_count)
	{
		for(int i = 0; i < p_count; ++i)
			p_dest[p_startDest + i] = p_src[p_startDest + i];
	}

	static void merge(std::vector<int> &p_toSortA, const int p_leftA, const int p_rightA,
					  std::vector<int> &p_toSortB, const int p_leftB, const int p_rightB,
					  std::vector<int> &p_toSortC, const int p_leftC)
	{
		int a = p_leftA;
		int b = p_leftB;
		int c = p_leftC;

		// go through both halfs of list
		while(a <= p_rightA && b <= p_rightB) {
			if(p_toSortA[a] <= p_toSortB[b]) {
				// half A has lower value so apply that value to
				// result list C
				p_toSortC[c] = p_toSortA[a];
				++c; ++a;
			} else {
				// half B has lower value so apply that value to
				// result list C
				p_toSortC[c] = p_toSortB[b];
				++c; ++b;
			}
		}

		if(b == p_rightB + 1) {
			// we finished the loop because B expired
			// apply remaining values in A into result C
			while(a <= p_rightA) {
				p_toSortC[c] = p_toSortA[a];
				++c; ++a;
			}
		} else {
			// we finished the loop because A expired
			// apply remaining values in A into result C
			while(b <= p_rightB) {
				p_toSortC[c] = p_toSortB[b];
				++c; ++b;
			}
		}
	}

	static void mergeSort(std::vector<int> &p_toSortA, const int p_left, const int p_right, std::vector<int> &p_toSortB)
	{
		if(p_right > p_left) {
			// divide list into half
			int mid = (p_left + p_right) / 2;

			mergeSort(p_toSortA, p_left, mid, p_toSortB);
			mergeSort(p_toSortA, mid + 1, p_right, p_toSortB);

			merge(p_toSortA, p_left, mid, p_toSortA, mid + 1, p_right, p_toSortB, p_left);
			copy(p_toSortB, p_left, p_toSortA, p_left, p_right - p_left + 1);
		}
	}

	void mergeSort(std::vector<int> &p_toSort)
	{
		std::vector<int> helper(p_toSort.size());
		mergeSort(p_toSort, 0, p_toSort.size() - 1, helper);
	}
}
