#include <array>
#include <iostream>
#include <vector>




class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        auto size {nums.size()};
        int moreThanHalf { static_cast<int>((size +1)/ 2) };

        std::array<int,10> counter {0,0,0,0,0,0,0,0,0,0};

        for (int num: nums) {
            if (moreThanHalf==++counter[num])
                return num;
        }
        return -1;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}