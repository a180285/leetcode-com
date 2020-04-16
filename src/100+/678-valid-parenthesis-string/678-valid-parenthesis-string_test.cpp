#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p678 {


    class Solution {
    public:
        bool checkValidString(string s) {
            s = " " + s;
            int sn = s.size();
            vector<vector<int>> dp(sn + 10, vector<int>(sn + 10));

            dp[0][0] = 1;

            for (int i = 1; i < sn; i++) {
                switch (s[i]) {
                    case '(':
                        for (int j = 1; j < sn ; j++) {
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                        break;
                    case ')':
                        for (int j = 0; j < sn ; j++) {
                            dp[i][j] = dp[i - 1][j + 1];
                        }
                        break;
                    default: // '*'
                        dp[i][0] = dp[i - 1][0] | dp[i - 1][1];
                        for (int j = 1; j < sn ; j++) {
                            dp[i][j] = dp[i - 1][j - 1] | dp[i - 1][j] | dp[i - 1][j + 1];
                        }
                        break;
                }
            }
            return dp[sn - 1][0] == 1;
        }
    };

    
    TEST(LeetCode, p678) {
        Solution s;
        EXPECT_EQ(s.checkValidString("()"), true);
        EXPECT_EQ(s.checkValidString("(*)"), true);
        EXPECT_EQ(s.checkValidString("(*))"), true);
        EXPECT_EQ(s.checkValidString(")(*))"), false);
    }
}
