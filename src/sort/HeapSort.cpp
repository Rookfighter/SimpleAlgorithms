#include "sort/sort.hpp"

namespace sa
{
    static int parentIdx(const int p_idx)
    {
        return (p_idx - 1) / 2;
    }

    static void downheap(std::vector<int> &p_toSort, const int p_count,
            const int p_idx)
    {
        int idx = p_idx;
        int value = p_toSort[idx];

        while(2 * idx + 1 < p_count) {
            int child = 2 * idx + 1;
            if(child + 1 < p_count && p_toSort[child + 1] > p_toSort[child]) {
                // right child has bigger value, so we use this one
                ++child;
            }

            if(value >= p_toSort[child]) {
                // parent value is bigger, so it is in right position
                break;
            }

            p_toSort[idx] = p_toSort[child];
            idx = child;
        }

        p_toSort[idx] = value;
    }

    static void heapify(std::vector<int> &p_toSort, const int p_count)
    {
        // begin with last non leaf node (parent of last node)
        // downheap from bottom up
        for(int i = parentIdx(p_count - 1); i >= 0; i--) {
            downheap(p_toSort, p_count, i);
        }
    }

    void heapSort(std::vector<int> &p_toSort)
    {
        heapify(p_toSort, p_toSort.size());

        for(int i = p_toSort.size() - 1; i > 0; --i) {
            int tmp = p_toSort[0];
            p_toSort[0] = p_toSort[i];
            p_toSort[i] = tmp;
            downheap(p_toSort, i, 0);
        }
    }
}
