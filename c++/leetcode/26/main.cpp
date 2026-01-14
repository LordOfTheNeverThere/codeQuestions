#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    static Int removeDuplicates(std::vector<Int>& nums) {

        Int uniqueIndex {0};
        for (const Int& num: nums) {

            if (num > nums[uniqueIndex]) {
                uniqueIndex++;
                nums[uniqueIndex] = num;
            }
        }
        return uniqueIndex + 1;
    }
};


int main() {
    std::vector<Int> nums {0,0,1,1,1,2,2,3,3,4};

    std::cout << Solution::removeDuplicates(nums);
    return 0;
}
