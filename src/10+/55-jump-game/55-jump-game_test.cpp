#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p55 {


    class Solution {
    public:
        bool canJump(const vector<int>& nums) {
            int maxJump = 0;
            for (int i = 0; i < nums.size() && i <= maxJump; i++) {
                maxJump = max(maxJump, nums[i] + i);
            }
            return maxJump >= nums.size() - 1;
        }
    };


    
    TEST(LeetCode, p55) {
        Solution s;
        EXPECT_EQ(s.canJump({3,2,1,0,4}), false);
        EXPECT_EQ(s.canJump({3,2,1,1,4}), true);
    }
}
