#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    bool static increasingTriplet(std::vector<int>& nums) {
        Int initialIndex {0};
        Int middleIndex {0};
        Int ite {1};
        if (nums.size() < 3) {
            return false;
        }

        while (initialIndex < nums.size() - 2) {


            if (ite == nums.size()) {
                initialIndex++;
                middleIndex = initialIndex;
                ite = initialIndex + 1;
            } else if ((middleIndex > initialIndex) && nums[middleIndex] < nums[ite]) {
                return  true;
            } else if (nums[initialIndex] < nums[ite])  {
                middleIndex = ite;
                ite++;
            } else {
                ite++;
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