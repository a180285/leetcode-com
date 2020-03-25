#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p1388 {


    class Solution {
    public: // a little slow, qaq
        int maxSizeSlices(vector<int>&& slices) {
            int n = slices.size();

            slices.insert(slices.end(), slices.begin(), slices.end());

            vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1));

            for (int len = 3; len <= n; len += 3) {
                for (int start = 0; start + len <= 2 * n; start++) {
                    auto& result = dp[start][start + len];
                    // x + 3 + y
                    for (int id = 0; id < len; id += 3) {
                        result = max(result, dp[start][start + id] + slices[start + id + 1] + dp[start + id + 3][start + len]);
                    }
                    // 1 + x + 2
                    result = max(result, dp[start + 1][start + len - 2] + slices[start + len - 2]);
                    // 2 + y + 1
                    result = max(result, dp[start + 2][start + len - 1] + slices[start + 1]);
                    // 1 + x + 1 + y + 1
                    for (int x = 3; x < len - 3; x += 3) {
                        result = max(result, dp[start + 1][start + 1 + x] + slices[start + 1 + x] + dp[start + 1 + x + 1][start + len - 1]);
                    }
                }
            }

            int result = 0;
            for (int start = 0; start < n; start++) {
                result = max(result, dp[start][start + n]);
            }
            return result;
        }
    };


    
    TEST(LeetCode, p1388) {
        Solution s;
        EXPECT_EQ(s.maxSizeSlices({4,1,2,5,8,3,1,9,7}), 21);
        EXPECT_EQ(s.maxSizeSlices({8,9,8,6,1,1}), 16);
    }
}
