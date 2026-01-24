#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    bool static increasingTriplet(std::vector<Int>& nums) {

        Int i {0};
        Int j {-1};

        for (Int ite {1}; ite < nums.size(); ite++) {
            if (nums[ite] <= nums[i]) {
                i = ite;
            } else if (j == -1 || nums[ite] <= nums[j]) {
                j = ite;
            } else if (nums[i] < nums[j] && nums[j] < nums[ite]) {
                return true;
            }
        }
        return false;

    }

};


int main() {


    std::vector<Int> vect {1,5,0,4,1,3};
    std::cout << Solution::increasingTriplet(vect) << std::endl;
    return 0;
}