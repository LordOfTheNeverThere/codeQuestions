#include <iostream>
#include <vector>

class Solution {
public:

    static void moveZeroes(std::vector<int>& nums) {
        int lastNonZeroIndex {-1};

        for (int& num: nums) {

            if (num) {
              lastNonZeroIndex++;
              move(num, nums[lastNonZeroIndex]);
            }
        }

    }

    static void printVector(std::vector<int>& nums) {
        for (int num: nums) {
            std::cout << num << ' ';
        }
    }
private:
    static void move(int& a, int& b) {
        if (&a != &b) { // If they are not the same
            int tmp {a};
            a = b;
            b = tmp;
        }
    }

};



int main() {
    std::vector<int> vector {1,0,0,0,1,1,0};

    Solution::moveZeroes(vector);

    Solution::printVector(vector);
}