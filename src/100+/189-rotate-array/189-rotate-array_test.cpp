#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p189 {

#endif



    class Solution {
        int gcd(int a, int b) {
            return a % b ? gcd(b, a % b) : b;
        }
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            if (n == 0 || k == 0) {
                return;
            }
            int g = gcd(n, k);

            while (g--) {
                int st = g;
                int tmp = nums[st];
                int q = (st + k) % n;
                while (q != st) {
                    swap(tmp, nums[q]);
                    q = (q + k) % n;
                }
                swap(tmp, nums[q]);
            }

        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p189) {
        Solution s;
//        EXPECT_EQ(s.rotate(0), 0);
    }
}

#endif
