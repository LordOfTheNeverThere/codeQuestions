#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    static void rotate(std::vector<Int>& nums, Int k) {



        Int const size = static_cast<Int>(nums.size());
        std::vector<Int> tempVector {};

        while (k >= size) {
            k = k - size;
        }

        if (k > size/2) {
            for (int i = 0; i < k; ++i) {
                tempVector.push_back(nums[i]);
            }

            for (int i = k; i < size; ++i) {
                if ((i + k) >= size) {
                    nums[i + k - size] = nums[i];
                } else {
                    nums[i + k] = nums[i];
                }
            }

            for (int i = 0; i < k; ++i) {

                if ((i + k) >= size) {
                    nums[i + k - size] = tempVector[i];
                }
                else {
                    nums[i + k] = tempVector[i];
                }
            }

        } else {


            for (int i = k; i < size; ++i) {
                tempVector.push_back(nums[i]);
            }

            for (int i = 0; i < k; ++i) {
                if ((i + k) >= size) {
                    nums[i + k - size] = nums[i];
                } else {
                    nums[i + k] = nums[i];
                }
            }

            for (int i = k; i < size; ++i) {
                if (i + k >= size) {
                    nums[i + k - size] = tempVector[i - k];
                } else {
                    nums[i + k] = tempVector[i - k];
                }

            }

        }


    }
};

int main() {
    std::vector<Int> vector {1,2,3};
    Solution::rotate(vector, 2);

    std::cout << vector[0] << std::endl;
    return 0;
}