#ifndef SRC_COLLECTIONS_DICTIONARY_HPP_
#define SRC_COLLECTIONS_DICTIONARY_HPP_

#include <cstddef>

namespace sa
{
    class Dictionary {
    public:
        Dictionary() { }
        virtual ~Dictionary() { }

        virtual void insert(const int p_key, const int p_value) = 0;
        virtual void remove(const int p_key) = 0;
        virtual bool contains(const int p_key) = 0;
        virtual int get(const int p_key) = 0;

        virtual std::size_t size() = 0;
        virtual bool empty() = 0;
        virtual void clear() = 0;
    };
}

#endif
