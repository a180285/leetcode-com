#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p201 {


    class Solution {
    public:
        int rangeBitwiseAnd(long long m, long long n) {
            long long between = n - m;
            m &= n;
            long long cnt = 0;
            while (between > 0) {
                cnt++;
                between >>= 1;
            }
            return m & ~( (1ll<<cnt) -1 );
        }
    };

    
    TEST(LeetCode, p201) {
        Solution s;
        EXPECT_EQ(s.rangeBitwiseAnd(3, 4), 0);
        EXPECT_EQ(s.rangeBitwiseAnd(5, 7), 4);
        EXPECT_EQ(s.rangeBitwiseAnd(5, 5), 5);
        EXPECT_EQ(s.rangeBitwiseAnd(6, 7), 6);
        EXPECT_EQ(s.rangeBitwiseAnd(0, 1), 0);
    }
}
