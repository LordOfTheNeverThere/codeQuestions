//
// Created by miguel on 1/29/26.
//

#ifndef BINARYTREE_BINARYSEARCHTREE_H
#define BINARYTREE_BINARYSEARCHTREE_H
#include <memory>

#include "TreeNode.h"
using Int = int32_t;

class BinarySearchTree {
private:

    std::unique_ptr<TreeNode> m_root {nullptr};

public:
    BinarySearchTree(Int val):
    m_root {std::make_unique<TreeNode>(val)} {}

    TreeNode* getRoot() const { return m_root.get();}
    void insert(Int value) {
        if (!m_root) {
            m_root = std::make_unique<TreeNode>(value);
        } else {
            m_root->insert(value);
        }
    }
    TreeNode* find(const Int value) {
        if (m_root) {
           return m_root->find(value);
        }
        return nullptr;
    }
    void remove(const Int value) {
        if (!m_root) {
            return;
        } else if (m_root->getValue() == value) {
            TreeNode::lumberjack(m_root, value);
        } else {
            m_root->remove(value);
        }
    }

};
#endif //BINARYTREE_BINARYSEARCHTREE_H