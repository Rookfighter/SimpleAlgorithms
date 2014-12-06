#include "sort/sort.hpp"

namespace sa
{
    void bubbleSort(std::vector<int> &p_toSort)
    {
        if(p_toSort.empty())
            return;

        for(unsigned int i = p_toSort.size() - 1; i != 0; --i) {

            bool swapped = false;
            for(unsigned int j = 0; j < i; ++j) {
                if(p_toSort[j] > p_toSort[j + 1]) {
                    int current = p_toSort[j];
                    p_toSort[j] = p_toSort[j + 1];
                    p_toSort[j + 1] = current;
                    swapped = true;
                }
            }

            if(!swapped)
                break;
        }
    }
}

