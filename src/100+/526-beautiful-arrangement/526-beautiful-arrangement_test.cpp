#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p526 {

#endif



    class Solution {
        int ans;
        int maxN;

        void dfs(int i, int flag) {
            if (flag == 0) {
                ans++;
                return;
            }
            for (int v = 1; v <= maxN; v++) {
                if (i % v != 0 && v % i != 0) {
                    continue;
                }
                int mask = (1 << (v - 1));
                if ((flag & mask) == 0) {
                    continue;
                }
                flag ^= mask;
                dfs(i + 1, flag);
                flag ^= mask;
            }
        }

    public:
        int countArrangement(int n) {
            ans = 0;
            maxN = n;
            dfs(1, (1 << n) - 1);
            return ans;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p526) {
        Solution s;
        EXPECT_EQ(s.countArrangement(2), 2);
        EXPECT_EQ(s.countArrangement(1), 1);
        EXPECT_EQ(s.countArrangement(15), 24679);
    }
}

#endif
