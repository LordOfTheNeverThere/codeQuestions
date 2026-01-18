#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>

using Int = int32_t;

class Solution {
public:
    std::vector<Int> productExceptSelf(std::vector<Int>& nums) {
        std::vector<Int> result {};
        std::pmr::unordered_set<Int> zeroPositions {};
        Int product {1};
        for (int i = 0; i < nums.size(); ++i) {

            if (nums[i] == 0) {
                zeroPositions.insert(i);
            } else {
                product = product * nums[i];
            }

            if (zeroPositions.size() >= 2) {
                product = 0;
                break;
            }
        }
        for (Int i=0; i < nums.size(); ++i) {
            if (zeroPositions.size() >= 2) {
                result.push_back(0);

            } else if (zeroPositions.find(i) != zeroPositions.end()) {
                result.push_back(product / 1);
            } else if (zeroPositions.size() == 1) {
                result.push_back(0);
            } else {
                result.push_back(product / nums[i]);
            }

        }

        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}