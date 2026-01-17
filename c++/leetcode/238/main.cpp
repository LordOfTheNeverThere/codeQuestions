#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    std::vector<Int> productExceptSelf(std::vector<Int>& nums) {
        std::vector<Int> result (nums.size());
        Int product {1};
        for (int i = 0; i < nums.size(); ++i) {
            product = product * nums[i];
        }
        for (Int num: nums) {
            result.push_back(product - num);
        }

        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}