#ifndef SRC_COLLECTIONS_PRIORITYQUEUE_HPP_
#define SRC_COLLECTIONS_PRIORITYQUEUE_HPP_

#include <vector>

namespace sa
{
    /* Highest value comes first */
    class PriorityQueue
    {
    private:
        std::vector<int> data_;

        unsigned int parentIndex(const unsigned int p_idx);
        void downheap(const unsigned int p_idx);
        void upheap(const unsigned int p_idx);
    public:
        PriorityQueue();
        ~PriorityQueue();

        void insert(const int p_value);
        int pop();

        std::size_t size();
        bool empty();
        void clear();
    };

}

#endif
