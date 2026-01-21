#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    long long zeroFilledSubarray(std::vector<Int>& nums) {
        Int currentSubArraySize {0};
        long long numOfSubArrays {0};

        for (Int num: nums) {
            if (num == 0) {
                numOfSubArrays = numOfSubArrays + 1 + currentSubArraySize;
                currentSubArraySize++;
            }
            else {
                currentSubArraySize = 0;
            }
        }
        return numOfSubArrays;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}