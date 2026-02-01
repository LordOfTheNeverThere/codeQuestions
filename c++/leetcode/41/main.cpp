
#include <memory>
#include <vector>

using Int = int32_t;


class Solution {
public:
    Int static firstMissingPositive(std::vector<Int>& nums) {
        Int size = nums.size();

        for (Int i = 0; i < size; ++i) {
            if (nums[i] > 0 && nums[i] <= size &&  i + 1 != nums[i]) {
                Int temp = nums[nums[i]-1]; // saved what is in i's home
                nums[nums[i]-1] = nums[i];//place i in its home
                nums[i] = temp;

                if (temp > 0 && temp <= size && temp != nums[temp-1]) { // if swapped number has a home and is not at home we must go to him a sort it.
                    i--;
                }
            }
        }
        Int result = 0;

        for (; result < size; ++result) {
            if (result + 1 != nums[result]) {
                break;
            }
        }
        return result +1;

    }
};



int main() {
    std::vector<Int> v {2,50000, 3, 4};
    Solution::firstMissingPositive(v);
    return 0;
}