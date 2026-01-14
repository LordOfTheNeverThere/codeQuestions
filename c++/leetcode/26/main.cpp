#include <iostream>
#include <unordered_set>
#include <vector>

using Int = int32_t;

class Solution {
public:
    static Int removeDuplicates(std::vector<Int>& nums) {
        std::unordered_set<Int> seenNums;
        Int& firstNonUnique {nums[0]};
        Int firstNonUniqueIndex = static_cast<Int>(nums.size());

        for (Int k = 0; k < nums.size(); k++) {

            if (&nums[k] == &nums[firstNonUniqueIndex]) {
                return k;
            }

            auto numInSet = seenNums.find(nums[k]);
            if (numInSet != seenNums.end()) {

                firstNonUniqueIndex--;
                std::swap(nums[k], nums[firstNonUniqueIndex]);

            } else {
                seenNums.insert(nums[k]);
            }
        }
        return 0;
    }
};



int main() {
    std::vector<Int> nums {0,0,1,1,1,2,2,3,3,4};

    std::cout << Solution::removeDuplicates(nums);
    return 0;
}
