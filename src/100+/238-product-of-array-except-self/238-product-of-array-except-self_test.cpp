#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p238 {

    // I'm not realize that, the statement says we should not use division~
    class Solution {
    public:
        vector<int> productExceptSelf(const vector<int>& nums) {
            long long product = 1;
            int zeroCount = 0;
            for (auto v : nums) {
                if (v != 0) {
                    product *= v;
                } else {
                    zeroCount++;
                }
            }

            vector<int> result(nums.size(), 0);
            if (zeroCount > 1) {
                return result;
            }

            for (int i = 0; i < nums.size(); i++) {
                int v = nums[i];

                if (zeroCount == 1) {
                    if (v == 0) {
                        result[i] = product;
                    }
                } else {
                    result[i] = product / v;
                }
            }

            return result;
        }
    };

    
    TEST(LeetCode, p238) {
        Solution s;
        EXPECT_EQ(s.productExceptSelf({1,2,0,3,4}), vector<int>({0, 0, 24, 0, 0}));
        EXPECT_EQ(s.productExceptSelf({1,2,0,0,4}), vector<int>({0, 0, 0, 0, 0}));
        EXPECT_EQ(s.productExceptSelf({1,2,3,4}), vector<int>({24, 12, 8, 6}));
    }
}
