#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p1395 {

#endif



    class Solution {
    public:
        int numTeams(vector<int>& rating) {
            vector<vector<int>> dp;
            dp.resize(3, vector<int>(rating.size()));
            dp[0].clear();
            dp[0].resize(rating.size(), 1);

            for (int k = 1; k < 3; k++) {
                for (int i = 1; i < rating.size(); i++) {
                    dp[k][i] = 0;
                    for (int j = 0; j < i; j++) {
                        if (rating[j] < rating[i]) {
                            dp[k][i] += dp[k - 1][j];
                        }
                    }
                }
            }

            int ans = accumulate(dp[2].begin(), dp[2].end(), 0);

            for (int k = 1; k < 3; k++) {
                for (int i = 1; i < rating.size(); i++) {
                    dp[k][i] = 0;
                    for (int j = 0; j < i; j++) {
                        if (rating[j] > rating[i]) {
                            dp[k][i] += dp[k - 1][j];
                        }
                    }
                }
            }

            return ans + accumulate(dp[2].begin(), dp[2].end(), 0);
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p1395) {
        Solution s;
//        EXPECT_EQ(s.numTeams(0), 0);
    }
}

#endif
