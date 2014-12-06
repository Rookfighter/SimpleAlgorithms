#ifndef SRC_COLLECTIONS_BINARYSEARCHTREE_HPP_
#define SRC_COLLECTIONS_BINARYSEARCHTREE_HPP_

namespace sa
{
    class BinarySearchTree
    {
    private:
        class Node {
        public:
            Node();
            ~Node();
            Node *left;
            Node *right;
            int data;
        };

        Node *root_;
        std::size_t size_;

        Node* insertRec(Node *p_node, const int p_value);
        Node* removeRec(Node *p_node, const int p_value);
        Node* getMin(Node *p_node) const;
        bool containsRec(Node *p_node, const int p_value) const;
        void clearRec(Node *p_node);
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(const int p_value);
        void remove(const int p_value);
        bool contains(const int p_value) const;

        std::size_t size() const;
        bool empty() const;
        void clear();
    };

}

#endif
