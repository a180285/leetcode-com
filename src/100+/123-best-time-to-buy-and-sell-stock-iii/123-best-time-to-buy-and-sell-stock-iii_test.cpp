#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p123 {


    class Solution {
    public:
        int maxProfit(const vector<int>& prices) {
            if (prices.empty()) {
                return 0;
            }
            vector<vector<int>> dp(prices.size(), vector<int>(4, INT_MIN));
            dp[0][0] = -prices[0];
            for (int i = 1; i < prices.size(); i++) {
                dp[i][0] = max(dp[i-1][0], -prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
                if (dp[i-1][1] == INT_MIN) {
                    continue;
                }
                dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i]);
                dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i]);
            }

            auto n = prices.size();
            return max(0, max(dp[n-1][1], dp[n-1][3]));
        }
    };


    
    TEST(LeetCode, p123) {
        Solution s;
        EXPECT_EQ(s.maxProfit({6,1,3,2,4,7}), 7);
        EXPECT_EQ(s.maxProfit({1,2,4}), 3);
        EXPECT_EQ(s.maxProfit({7,6,4,3,1}), 0);
        EXPECT_EQ(s.maxProfit({7,1,5,3,6,4}), 7);
        EXPECT_EQ(s.maxProfit({3,3,5,0,0,3,1,4}), 6);
        EXPECT_EQ(s.maxProfit({1,2,3,4,5}), 4);
    }
}
