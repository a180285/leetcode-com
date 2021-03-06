#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p1399 {

#endif



    class Solution {

        int sum(int n) {
            int ans = 0;
            while (n != 0) {
                ans += n % 10;
                n /= 10;
            }
            return ans;
        }

    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> sumCount;
            for (int i = 1; i <= n; i++) {
                sumCount[sum(i)]++;
            }
            int maxCount = 0;
            int numberOfCount = 0;
            for (auto [k, v] : sumCount) {
                if (v > maxCount) {
                    numberOfCount = 1;
                    maxCount = v;
                } else if (v == maxCount) {
                    numberOfCount++;
                }
            }
            return numberOfCount;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p1399) {
        Solution s;
        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
