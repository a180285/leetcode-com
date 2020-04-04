#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p283 {


    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            auto newEnd = remove_if(nums.begin(), nums.end(), [](int v){return v == 0;});
            fill(newEnd, nums.end(), 0);
        }
    };


    
    TEST(LeetCode, p283) {
        Solution s;
        vector<int> input{0,1,0,3,12};
        s.moveZeroes(input);

        EXPECT_EQ(input, vector<int>({1,3,12,0,0}));
    }
}
