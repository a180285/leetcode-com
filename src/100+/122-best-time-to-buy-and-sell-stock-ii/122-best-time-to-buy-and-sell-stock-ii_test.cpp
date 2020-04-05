#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p122 {


    class Solution {
    public:
        int maxProfit(const vector<int>& prices) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                profit += max(0, prices[i] - prices[i - 1]);
            }
            return profit;
        }
    };


    
    TEST(LeetCode, p122) {
        Solution s;
        EXPECT_EQ(s.maxProfit({7,6,4,3,1}), 0);
        EXPECT_EQ(s.maxProfit({7,1,5,3,6,4}), 7);
    }
}
