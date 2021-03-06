#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p902 {

#endif



    class Solution {
        vector<int> up;
        int dp[32][2];
        vector<int> digits;

        int dfs(int id, int limited) {
            if (id == 0) {
                return 1;
            }
            int& r = dp[id][limited];
            if (r != -1) {
                return r;
            }
            r = 0;
            int newUp = limited ? up[id - 1] : 9;
            for (int d : digits) {
                if (d > newUp) {
                    break;
                }
                r += dfs(id - 1, limited && d == newUp);
            }
            return r;
        }

    public:
        int atMostNGivenDigitSet(vector<string>& d, int n) {
            memset(dp, -1, sizeof(dp));
            while (n > 0) {
                up.push_back(n % 10);
                n /= 10;
            }

            for (auto s : d) {
                digits.push_back(s[0] - '0');
            }
            int sum = 0;
            for (int i = 1; i < up.size(); i++) {
                sum += dfs(i, 0);
            }
            return sum + dfs(up.size(), 1);
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p902) {
        vector<string> digits = {"1","3","5","7"};
        Solution s;
        EXPECT_EQ(s.atMostNGivenDigitSet(digits, 100), 20);
    }
}

#endif
