#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p_ {


    class Solution {
    public:
        int numTimesAllBlue(const vector<int> &light) {
            return 0;
        }
    };


    
    TEST(LeetCode, p_) {
        Solution s;
        EXPECT_EQ(s.numTimesAllBlue({2, 1, 3, 5, 4}), 0);
    }
}
