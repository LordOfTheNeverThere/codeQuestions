#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    static void rotate(std::vector<Int>& nums, Int k) {

        Int const size = static_cast<Int>(nums.size());
        

        for (Int i = 0; i < size - k - 1; ++i) {

        }


        for (Int i = size - k - 1; i < size; ++i) {

        }

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}