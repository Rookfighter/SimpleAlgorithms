#include <cstddef>
#include <cassert>
#include "collections/BinarySearchTree.hpp"

namespace sa
{
    BinarySearchTree::Node::Node()
            : left(NULL), right(NULL), data(0)
    {
    }

    BinarySearchTree::Node::~Node()
    {
    }

    BinarySearchTree::BinarySearchTree()
            : root_(NULL), size_(0)
    {

    }

    BinarySearchTree::~BinarySearchTree()
    {
        clear();
    }

    void BinarySearchTree::insert(const int p_value)
    {
        root_ = insertRec(root_, p_value);
    }

    BinarySearchTree::Node* BinarySearchTree::insertRec(Node *p_node, const int p_value)
    {
        Node* result;
        if(p_node == NULL) {
            result = new Node();
            result->data = p_value;
            ++size_;
        } else if(p_value < p_node->data) {
            p_node->left = insertRec(p_node->left, p_value);
            result = p_node;
        } else if(p_node->data < p_value) {
            p_node->right = insertRec(p_node->right, p_value);
            result = p_node;
        } else {
            // do nothing, no duplicate values allowed
            result = p_node;
        }

        return result;
    }

    void BinarySearchTree::remove(const int p_value)
    {
        root_ = removeRec(root_, p_value);
    }

    BinarySearchTree::Node* BinarySearchTree::removeRec(Node *p_node, const int p_value)
    {
        Node* result;
        if(p_node == NULL)
            result = NULL;
        else if(p_value < p_node->data) {
            p_node->left = removeRec(p_node->left, p_value);
            result = p_node;
        } else if(p_node->data < p_value) {
            p_node->right = removeRec(p_node->right, p_value);
            result = p_node;
        } else {
            if(p_node->left == NULL || p_node->right == NULL) {
                result = p_node->left != NULL ? p_node->left : p_node->right;
                delete p_node;
                --size_;
            } else {
                result = p_node;
                // search most left node in right subtree
                result->data = getMin(p_node->right)->data;
                // most left node only has 1 or 0 childnodes
                // decrement of size will be done there
                result->right = removeRec(result->right, result->data);
            }
        }

        return result;
    }

    BinarySearchTree::Node* BinarySearchTree::getMin(Node* p_node) const
    {
        assert(p_node != NULL);

        Node *result = p_node;
        while(result->left != NULL)
            result = result->left;
        return result;
    }

    bool BinarySearchTree::contains(const int p_value) const
    {
        return containsRec(root_, p_value);
    }

    bool BinarySearchTree::containsRec(Node* p_node, const int p_value) const
    {
        if(p_node == NULL)
            return false;
        else if(p_value < p_node->data)
            return containsRec(p_node->left, p_value);
        else if(p_node->data < p_value)
            return containsRec(p_node->right, p_value);
        else
            return true;
    }

    std::size_t BinarySearchTree::size() const
    {
        return size_;
    }

    bool BinarySearchTree::empty() const
    {
        return size_ == 0;
    }

    void BinarySearchTree::clear()
    {
        clearRec(root_);
        root_ = NULL;
        size_ = 0;
    }

    void BinarySearchTree::clearRec(Node* p_node)
    {
        if(p_node == NULL)
            return;
        else {
            clearRec(p_node->left);
            clearRec(p_node->right);
            delete p_node;
        }
    }

}

