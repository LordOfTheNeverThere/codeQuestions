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

        if (value < m_value) {
            if (!m_left) {
                m_left = std::move(std::make_unique<TreeNode>(value));
            } else {
                m_left->insert(value);
            }

        } else if (value > m_value) {
            if (!m_right) {
                m_right = std::move(std::make_unique<TreeNode>(value));
            } else {
                m_right->insert(value);
            }
        }
    }

    TreeNode* find(Int value) {
        if (value == m_value) {
            return this;
        } else if (m_left && value < m_value) {
            return m_left->find(value);
        } else if (m_right && value > m_value) {
            return m_right->find(value);
        } else {
            //this is a leaf, the end ...
            return nullptr;
        }
    }

    TreeNode* remove(Int value) {
        if (value == m_value) {
            if (m_left && m_right) { // Has both children
                // in this case in order to not break the BST condition we must substitue this node with
                // the one with the lesser value of the m_right subtree
                TreeNode* bstMINNode = m_right->findAndRemoveBSTMin();
                m_value = bstMINNode->getValue();
                return bstMINNode;

            } else if (m_left) { // Has Leftmost children
                return m_left.get();
            }
            else if (m_right) { // Has Rightmost children
                return m_right.get();
            }
            else { // Has no children = Leaf node
                return nullptr;
            }
        } else if (m_left && value < m_value) {
            return m_left->remove(value);
        } else if (m_right && value > m_value) {
            return m_right->remove(value);
        }
    }

    TreeNode* findAndRemoveBSTMin() {
        if ((m_left->getLeft())) {
            return m_left->findAndRemoveBSTMin();
        } else {
            TreeNode* min = m_left.get();
            m_left.reset(m_left->getRight());
            return min;
        }
    }
};

#include "TreeNode.h"