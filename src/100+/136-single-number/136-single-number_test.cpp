#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p136 {


    class Solution {
    public:
        int singleNumber(const vector<int>& nums) {
            int ret = 0;
            for (auto x : nums) {
                ret ^= x;
            }
            return ret;
        }
    };


    
    TEST(LeetCode, p136) {
        Solution s;
        EXPECT_EQ(s.singleNumber({4,1,2,1,2}), 4);
    }
}
