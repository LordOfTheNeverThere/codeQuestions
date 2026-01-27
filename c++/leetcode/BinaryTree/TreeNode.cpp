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

    TreeNode* find(const Int value) {
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

    Int findAndRemoveBSTMin() {
        if (!m_left) {
            return this->getValue();
        } else if ((m_left->getLeft())) {
            return m_left->findAndRemoveBSTMin();
        } else {
            const Int min = m_left->getValue();
            m_left = std::move(m_left->m_right);
            return min;
        }
    }

    void lumberjack(std::unique_ptr<TreeNode>& nodeToCut, const Int value) {
        if (nodeToCut->getValue() == value) {
            if ((nodeToCut->getLeft()) && (nodeToCut->getRight())) { // Has both children
                // in this case in order to not break the BST condition we must substitue this node with
                // the one with the lesser value of the m_right subtree
                nodeToCut->m_value = nodeToCut->getRight()->findAndRemoveBSTMin();
            } else if (nodeToCut->getLeft()) { // Has Leftmost children
                nodeToCut = std::move(nodeToCut->m_left);
            }
            else if (nodeToCut->getRight()) { // Has Rightmost children
                nodeToCut = std::move(nodeToCut->m_right);
            }
            else { // Has no children = Leaf node
                nodeToCut.reset(nullptr);
            }
        } else {
            nodeToCut->remove(value);
        }
    }

    void remove(const Int value) {
        if (value < m_value && m_left) {
            lumberjack(m_left, value);
        } else if (value > m_value && m_right) {
            lumberjack(m_right, value);
        }
    }
};

#include "TreeNode.h"