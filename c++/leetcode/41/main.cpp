#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using Int = int32_t;


class SortedNode {
public:
    Int m_val {0};
    std::unique_ptr<SortedNode> m_next {nullptr};
    SortedNode* m_prev {nullptr};

    SortedNode(Int value):
    m_val {value} {}


    Int getVal() {return m_val;}
    SortedNode* getNext() {return m_next.get();}
    SortedNode* getPrev() {return m_prev;}

    void insert(Int value) {
        if (value == m_val) {
            return;
        } else if (!m_next) {
            m_next = std::make_unique<SortedNode>(SortedNode(value));
        } else if (value < m_next->getVal()) {
            // - o1 - o2 - <=> o1 - o3 - o2 where o1<o3<o2
            auto newNodePtr = std::make_unique<SortedNode>(SortedNode(value));
            SortedNode* newNode = newNodePtr.get();
            newNode->changePrev(this);
            newNode->changeNext(m_next);
            newNode->m_next->changePrev(newNode);
            changeNext(newNodePtr);
        } else {
            m_next->insert(value);
        }

    }
    void changePrev(SortedNode* newPrev) {
        m_prev = newPrev;
    }
    void changeNext(std::unique_ptr<SortedNode>& newNext) {
        m_next = std::move(newNext);
    }
};

class SortedList {
public:
    std::unique_ptr<SortedNode> m_root {nullptr};

    void insert(Int value) {
        if (value <= 0) {
            return;
        }
        if (!m_root) {
            m_root = std::make_unique<SortedNode>(SortedNode(value));
        } else {
            if (value < m_root->getVal()) {

                auto newNodePtr = std::make_unique<SortedNode>(SortedNode(value));
                SortedNode* newNode = newNodePtr.get();
                newNode->changeNext(m_root);
                newNode->m_next->changePrev(newNode);
                m_root = std::move(newNodePtr);
            } else {
                m_root->insert(value);
            }

        }
    }

    Int findLowestMissingInt() {
        if (!m_root || m_root->getVal() != 1) {
            return 1;
        } else {
            SortedNode* currNode {m_root.get()};
            Int min {2};
            while (currNode) {
                if (!currNode->m_next) {
                    break;
                }
                if (currNode->m_next->getVal() != min) {
                    return min;
                } else {
                    currNode = currNode->getNext();
                    min++;
                }
            }
            return min;
        }
    }


};


class Solution {
public:
    Int static firstMissingPositive(std::vector<Int>& nums) {
        SortedList sList = SortedList();
        for (auto num: nums) {
            sList.insert(num);
        }

        return sList.findLowestMissingInt();

    }
};



int main() {
    std::vector<Int> v {2,1};
    Solution::firstMissingPositive(v);
    return 0;
}