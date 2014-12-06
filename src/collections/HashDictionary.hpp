#ifndef SRC_COLLECTIONS_HASHDICTIONARY_HPP_
#define SRC_COLLECTIONS_HASHDICTIONARY_HPP_

#include <vector>
#include "collections/Dictionary.hpp"

namespace sa
{

    class HashDictionary: public Dictionary
    {
    private:
        struct Pair {
            enum State {EMPTY, DELETED, USED};
            State state = EMPTY;
            int key = 0;
            int value = 0;
        };

        std::vector<Pair> hashTable_;
        std::size_t size_;

        unsigned int getHashIndex(const int p_key, const unsigned int p_count) const;
        unsigned int getHashValue(const int p_key) const;
        unsigned int getDoubleHashValue(const int p_key) const;
    public:
        HashDictionary();
        ~HashDictionary();

        void insert(const int p_key, const int p_value);
        void remove(const int p_key);
        bool contains(const int p_key);
        int get(const int p_key);

        std::size_t size();
        bool empty();
        void clear();
    };

}

#endif
