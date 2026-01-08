#include <iostream>
#include <vector>


using Int = int32_t;

struct UnaryCounter {
    Int number;
    Int freq;
};

class NumberFreqCounter {
private:
    std::vector<UnaryCounter> mCounter{UnaryCounter {0,0}};
public:
    Int findNumber(Int query) const {
        for (int i = 0; i < mCounter.size(); ++i) {
            if (mCounter[i].number == query) {
                return i;
            }
        }
        return -1;
    }

    void incrementUnaryCounter(Int index, Int number) {
        if (index == -1) {
            mCounter.push_back(UnaryCounter {number , 1});
        } else {
            mCounter[index].freq++;
        }

    }

    Int& getNumberFreq(Int index) {
        if (index==-1) {
            return mCounter.back().freq;
        }

        return mCounter[index].freq;
    }

    Int& getNumber(Int index) {
        if (index==-1) {
            return mCounter.back().number;
        }
        return mCounter[index].number;
    }
};


class Solution {
public:
    Int majorityElement(std::vector<Int>& nums) {
        auto size {nums.size()};
        Int moreThanHalf { static_cast<Int>((size +1)/ 2) };
        NumberFreqCounter resCounter {};

        for (Int num: nums) {
            Int counterIndex {resCounter.findNumber(num)};
            resCounter.incrementUnaryCounter(counterIndex, num);

            if (resCounter.getNumberFreq(counterIndex) == moreThanHalf) {
                return resCounter.getNumber(counterIndex);
            }
        }

        return -1; //No majority Element found (should not happen)
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}