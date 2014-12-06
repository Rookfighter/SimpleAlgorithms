#include <stdexcept>
#include "collections/PriorityQueue.hpp"

namespace sa
{
    PriorityQueue::PriorityQueue()
    {
    }

    PriorityQueue::~PriorityQueue()
    {
    }

    unsigned int PriorityQueue::parentIndex(const unsigned int p_idx)
    {
        return (p_idx - 1) / 2;
    }

    void PriorityQueue::downheap(const unsigned int p_idx)
    {
        unsigned int idx = p_idx;
        int value = data_[idx];

        while(2 * idx + 1 < data_.size()) {
            unsigned int child = 2 * idx + 1;
            if(child + 1 < data_.size() && data_[child + 1] > data_[child]) {
                // right child has bigger value, so we use this one
                ++child;
            }

            if(value >= data_[child]) {
                // parent value is bigger, so it is in right position
                break;
            }

            data_[idx] = data_[child];
            idx = child;
        }

        data_[idx] = value;
    }

    void PriorityQueue::upheap(const unsigned int p_idx)
    {
        unsigned int idx = p_idx;
        int value = data_[idx];

        while(idx > 0 && data_[parentIndex(idx)] < value) {
            data_[idx] = data_[parentIndex(idx)];
            idx = parentIndex(idx);
        }

        data_[idx] = value;
    }

    void PriorityQueue::insert(const int p_value)
    {
        data_.push_back(p_value);
        upheap(data_.size() - 1);
    }

    int PriorityQueue::pop()
    {
        if(data_.empty())
            throw std::logic_error("queue is empty. cannot pop");

        int result = data_[0];
        data_[0] = data_.back();
        data_.pop_back();
        downheap(0);

        return result;
    }

    std::size_t PriorityQueue::size()
    {
        return data_.size();
    }

    bool PriorityQueue::empty()
    {
        return data_.empty();
    }

    void PriorityQueue::clear()
    {
        data_.clear();
    }

}
