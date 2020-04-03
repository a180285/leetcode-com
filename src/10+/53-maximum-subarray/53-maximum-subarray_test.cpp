#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p53 {


    class Solution {
    public:
        int maxSubArray(const vector<int>& nums) {
            vector<int> sums(nums.size());
            int maxSum = nums[0];
            sums[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                sums[i] = nums[i];
                if (sums[i-1] > 0) {
                    sums[i] += sums[i-1];
                }
                maxSum = max(maxSum, sums[i]);
            }
            return maxSum;
        }
    };


    
    TEST(LeetCode, p53) {
        Solution s;
        EXPECT_EQ(s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}), 6);
    }
}
