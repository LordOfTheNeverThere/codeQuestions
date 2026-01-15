#include <iostream>
#include <vector>



class Solution {
public:
    static int profit(int const& buyInd, int const& sellInd, std::vector<int>& prices) {
        return prices[sellInd] - prices[buyInd];
    }

    static int maxProfit(std::vector<int>& prices) {
        int minIndex {0};
        int maxIndex {0};

        int buyIndex {minIndex};
        int sellIndex {maxIndex};

        for (int i = 1; i < prices.size(); i++ ) {

            if ((prices[i] > prices[maxIndex])) {
                maxIndex = i;
            } else if (prices[i] < prices[minIndex]) {
                minIndex = i;
                maxIndex = i;
            }

            if (minIndex < maxIndex &&
                (profit(minIndex, maxIndex, prices) > profit(buyIndex, sellIndex, prices))
                ) {

                //Update
                buyIndex = minIndex;
                sellIndex = maxIndex;
                }
        }
        return profit(buyIndex, sellIndex, prices);
    }
};






int main() {
    std::vector<int> vector {7,1,5,3,6,4};
    std::cout << Solution::maxProfit(vector);
    return 0;
}