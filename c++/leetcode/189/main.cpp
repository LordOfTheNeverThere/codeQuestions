#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    static void rotate(std::vector<Int>& nums, Int k) {

        Int const size = static_cast<Int>(nums.size());
        std::vector<Int> tempVector (size);

        for (int i = 0; i < size; ++i) {

            tempVector[(i + k) % size] =  nums[i];
        }

        nums = std::move(tempVector);
    }
};

int main() {
    std::vector<Int> vector {1,2,3};
    Solution::rotate(vector, 2);

    std::cout << vector[0] << std::endl;
    return 0;
}