#include <memory>

using Int = int32_t;

class TreeNode {
private:
    Int m_value {};
    std::unique_ptr<TreeNode> m_left {nullptr};
    std::unique_ptr<TreeNode> m_right {nullptr};

public:
    TreeNode(Int val)
    : m_value { val } {}

    Int getValue() { return m_value;}
    TreeNode* getLeft() const { return m_left.get();}
    TreeNode* getRight() const { return m_right.get();}

    void setLeft(TreeNode node) {
        m_left = std::make_unique<TreeNode>(std::move(node));
    }
    void setRight(TreeNode node) {
        m_right = std::make_unique<TreeNode>(std::move(node));
    }

    void insert(Int value) {
        auto newNode {std::make_unique<TreeNode>(value)};

        if (value < m_value) {
            if (!m_left) {
                m_left = std::move(newNode);
            } else {
                m_left->insert(value);
            }

        } else if (value > m_value) {
            if (!m_right) {
                m_right = std::move(newNode);
            } else {
                m_right->insert(value);
            }
        }
    }

    TreeNode* find(Int value) {
        if (value == m_value) {
            return this;
        } else if (!m_left && value < m_value) {
            return m_left->find(value);
        } else if (!m_right && value > m_value) {
            return m_right->find(value);
        } else {
            //this is a leaf, the end ...
            return nullptr;
        }
    }

    void remove(Int value) {

        if (!m_left && m_left.get()->getValue() == value) {
            

        } else if (!m_right && m_right.get()->getValue() == value) {

        } else if (!m_left && m_value > value ) {
            m_left.get()->remove(value);

        } else if (!m_right && m_value < value ) {
            m_right.get()->remove(value);
        }
    }
};

#include "TreeNode.h"