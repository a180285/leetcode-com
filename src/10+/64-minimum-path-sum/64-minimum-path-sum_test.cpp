#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p64 {


    class Solution {
    public:
        int minPathSum(const vector<vector<int>>& grid) {
            int r = grid.size();
            int c = grid[0].size();
            vector<vector<int>> dp(r, vector<int>(c));

            dp[0][0] = grid[0][0];
            for (int i = 1; i < r; i++) {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            }
            for (int j = 1; j < c; j++) {
                dp[0][j] = dp[0][j - 1] + grid[0][j];
            }
            for (int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                }
            }
            return dp[r-1][c-1];
        }
    };


    
    TEST(LeetCode, p64) {
        Solution s;
        EXPECT_EQ(s.minPathSum({
            { 1, 3, 1 },
            { 1, 5, 1 },
            { 4, 2, 1 },
        }), 7);
    }
}
