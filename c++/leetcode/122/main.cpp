#include <iostream>
#include <vector>

using Int = int32_t;

class Solution {
public:
    Int static maxProfit(std::vector<Int>& prices) {

        Int currStockIndex {-1};
        Int profit {0};

        for (Int i = 0; i < prices.size(); ++i) {

            if (i == prices.size() - 1 && (currStockIndex != -1)) {
                profit = profit + (prices[i] - prices[currStockIndex]);//Sell
                currStockIndex = -1;

            } else if (i == prices.size() - 1 && (currStockIndex == -1)) {
                break; // Should not buy on the last day

            } else if (currStockIndex == -1 && (prices[i] < prices[i+1])) {
                currStockIndex = i; //Buy

            } else if (currStockIndex != -1 && (prices[i] > prices[i+1])) {
                profit = profit + (prices[i] - prices[currStockIndex]);//Sell
                currStockIndex = -1;
            }
        }
        return profit;

    }
};


int main() {

    std::vector<Int> prices {2,1,2,0,1};
    std::cout << Solution::maxProfit(prices) << std::endl;
    return 0;
}