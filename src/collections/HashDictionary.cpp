#include <stdexcept>
#include "collections/HashDictionary.hpp"

#define INIT_HASH_TABLE_SIZE 7

namespace sa
{

    HashDictionary::HashDictionary()
            : hashTable_(INIT_HASH_TABLE_SIZE), size_(0)
    {
    }

    HashDictionary::~HashDictionary()
    {
    }

    void HashDictionary::insert(const int p_key, const int p_value)
    {
        unsigned int idx = 0;
        unsigned int count = 0;

        do {
            idx = getHashIndex(p_key, count);
            if(hashTable_[idx].state == Pair::State::EMPTY)
                break;
            if(hashTable_[idx].state == Pair::State::USED
                    && hashTable_[idx].key == p_key)
                break;
            ++count;
        } while(true);

        hashTable_[idx].value = p_value;

        if(hashTable_[idx].state != Pair::State::USED) {
            // this key was not in the dict before
            hashTable_[idx].key = p_key;
            hashTable_[idx].state = Pair::State::USED;
            ++size_;
        }

    }

    void HashDictionary::remove(const int p_key)
    {
        unsigned int idx = 0;
        unsigned int count = 0;

        do {
            idx = getHashIndex(p_key, count);
            if(hashTable_[idx].state == Pair::State::EMPTY)
                break;
            if(hashTable_[idx].state == Pair::State::USED
                    && hashTable_[idx].key == p_key)
                break;
            ++count;
        } while(true);

        if(hashTable_[idx].state != Pair::State::EMPTY) {
            hashTable_[idx].state = Pair::State::DELETED;
            --size_;
        }
    }

    bool HashDictionary::contains(const int p_key)
    {
        unsigned int idx = 0;
        unsigned int count = 0;

        do {
            idx = getHashIndex(p_key, count);
            if(hashTable_[idx].state == Pair::State::EMPTY)
                break;
            if(hashTable_[idx].state == Pair::State::USED
                    && hashTable_[idx].key == p_key)
                break;
            ++count;
        } while(true);

        return hashTable_[idx].state != Pair::State::EMPTY;
    }

    int HashDictionary::get(const int p_key)
    {
        unsigned int idx = 0;
        unsigned int count = 0;

        do {
            idx = getHashIndex(p_key, count);
            if(hashTable_[idx].state == Pair::State::EMPTY)
                break;
            if(hashTable_[idx].state == Pair::State::USED
                    && hashTable_[idx].key == p_key)
                break;
            ++count;
        } while(true);

        if(hashTable_[idx].state != Pair::State::EMPTY)
            return hashTable_[idx].value;
        else
            throw std::logic_error("element not found");
    }

    std::size_t HashDictionary::size()
    {
        return size_;
    }

    bool HashDictionary::empty()
    {
        return size_ == 0;
    }

    unsigned int HashDictionary::getHashIndex(const int p_key,
            const unsigned int p_count) const
    {
        return (getHashValue(p_key) + p_count * getDoubleHashValue(p_key))
                % hashTable_.size();
    }

    unsigned int HashDictionary::getHashValue(const int p_key) const
    {
        return ((unsigned int) p_key) % hashTable_.size();
    }

    unsigned int HashDictionary::getDoubleHashValue(const int p_key) const
    {
        return (((unsigned int) p_key) + 1) % (hashTable_.size() - 2);
    }

    void HashDictionary::clear()
    {
        hashTable_.clear();
        hashTable_.resize(INIT_HASH_TABLE_SIZE);
        size_ = 0;
    }

}
