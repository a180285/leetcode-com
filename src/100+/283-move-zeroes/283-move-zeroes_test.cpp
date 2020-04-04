#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p283 {


    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int next = 0;
            for (auto v : nums) {
                if (v != 0) {
                    nums[next++] = v;
                }
            }
            fill(nums.begin() + next, nums.end(), 0);
        }
    };


    
    TEST(LeetCode, p283) {
        Solution s;
        vector<int> input{0,1,0,3,12};
        s.moveZeroes(input);

        EXPECT_EQ(input, vector<int>({1,3,12,0,0}));
    }
}
