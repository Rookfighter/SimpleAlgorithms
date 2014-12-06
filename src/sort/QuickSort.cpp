#include "sort/sort.hpp"

namespace sa
{
    static int getMedian3(std::vector<int> &p_toSort, const int p_left,
            const int p_right)
    {
        int mid = (p_left + p_right) / 2;
        int median;

        if(p_toSort[p_left] > p_toSort[mid]) {
            if(p_toSort[mid] > p_toSort[p_right]) {
                median = mid;
            } else if(p_toSort[p_left] > p_toSort[p_right]) {
                median = p_right;
            } else {
                median = p_left;
            }
        } else {
            if(p_toSort[p_left] > p_toSort[p_right]) {
                median = p_left;
            } else if(p_toSort[mid] > p_toSort[p_right]) {
                median = p_right;
            } else {
                median = mid;
            }
        }

        return median;
    }

    static int partition(std::vector<int> &p_toSort, const int p_left,
            const int p_right)
    {
        // if list is sorted getting the median performs better
        // than just using the rightest element
        int median = getMedian3(p_toSort, p_left, p_right);
        int pivot = p_toSort[median];
        p_toSort[median] = p_toSort[p_right];
        p_toSort[p_right] = pivot;

        int i = p_left - 1;
        int j = p_right;

        while(true) {
            do
                ++i;
            while(p_toSort[i] < pivot);
            do
                --j;
            while(j > i && p_toSort[j] > pivot);

            if(j <= i) {
                // all smaller elementes moved to left
                // and all bigger elements moved to right
                break;
            }

            // swap most left element of right side with pivot element
            int tmp = p_toSort[i];
            p_toSort[i] = p_toSort[j];
            p_toSort[j] = tmp;
        }

        p_toSort[p_right] = p_toSort[i];
        p_toSort[i] = pivot;

        return i;
    }

    static void quickSort(std::vector<int> &p_toSort, const int p_left,
            const int p_right)
    {
        int left = p_left;
        int right = p_right;
        while(right > left) {
            int mid = partition(p_toSort, left, right);

            if(mid - left < right - mid) {
                // left side has less elements
                // recursion on the left side to prevent stack overflow
                quickSort(p_toSort, left, mid - 1);
                left = mid + 1;
            } else {
                // right side has less elements
                // recursion on the right side to prevent stack overflow
                quickSort(p_toSort, mid + 1, right);
                right = mid - 1;
            }
        }
    }

    void quickSort(std::vector<int> &p_toSort)
    {
        quickSort(p_toSort, 0, p_toSort.size() - 1);
    }

}
