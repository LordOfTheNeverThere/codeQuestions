 //
// Created by
#ifndef BINARYTREE_TREENODE_H
#define BINARYTREE_TREENODE_H


using Int = int32_t;

class TreeNode {
 friend class BinarySearchTree;
private:
 Int m_value {};
 std::unique_ptr<TreeNode> m_left {nullptr};
 std::unique_ptr<TreeNode> m_right {nullptr};

 static Int findAndRemoveBSTMin(std::unique_ptr<TreeNode>& rightSubTreeRoot);
 static void lumberjack(std::unique_ptr<TreeNode>& nodeToCut, const Int value);

public:
 TreeNode(Int val);

 Int getValue() const { return m_value; }
 TreeNode* getLeft() const { return m_left.get(); }
 TreeNode* getRight() const { return m_right.get(); }

 void insert(Int value);
 TreeNode* find(const Int value);
 void remove(const Int value);
};

#endif //BINARYTREE_TREENODE_H