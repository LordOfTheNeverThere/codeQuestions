#include <iostream>
#include "BinarySearchTree.h"

void printResult(const std::string& testName, bool success) {
    std::cout << (success ? "✅ " : "❌ ") << testName << std::endl;
}

int main() {
    // 1. Initialization & Insertion
    // Starting with 50 as the root
    BinarySearchTree bst(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // 2. Test Finding (Search)
    // Testing logic in TreeNode::find
    printResult("Find existing value (20)", bst.find(20) != nullptr);
    printResult("Find existing value (80)", bst.find(80) != nullptr);
    printResult("Find non-existent value (99)", bst.find(99) == nullptr);

    // 3. Test Removal - Case 1: Leaf Node (No children)
    // Handled by the 'else' block in lumberjack
    bst.remove(20);
    printResult("Remove leaf node (20)", bst.find(20) == nullptr);

    // 4. Test Removal - Case 2: One Child
    // Handled by move(m_left) or move(m_right) in lumberjack
    bst.remove(30); // 40 will move up to take 30's place
    printResult("Remove node with one child (30)", bst.find(30) == nullptr);
    printResult("Verify child (40) still exists", bst.find(40) != nullptr);

    // 5. Test Removal - Case 3: Two Children (The "Lumberjack" special)
    // Uses findAndRemoveBSTMin to find successor
    bst.remove(50); // Root removal
    printResult("Remove root with two children (50)", bst.find(50) == nullptr);
    printResult("Verify tree integrity (70 still exists)", bst.find(70) != nullptr);

    std::cout << "\nAll basic tests complete!" << std::endl;

    return 0;
}