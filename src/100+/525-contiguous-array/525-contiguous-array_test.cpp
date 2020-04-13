#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p525 {


    class Solution {
    public:
        int findMaxLength(const vector<int>& nums) {
            map<int, int> firstIndex;
            int cnt = 0;
            firstIndex[cnt] = -1;
            int maxLength = 0;

            for (int i = 0; i < nums.size(); i++) {
                cnt += -1 + 2 * nums[i];
                auto it = firstIndex.find(cnt);
                if (it != firstIndex.end()) {
                    maxLength = max(maxLength, i - it->second);
                } else {
                    firstIndex[cnt] = i;
                }
            }

            return maxLength;
        }
    };


    
    TEST(LeetCode, p525) {
        Solution s;
        EXPECT_EQ(s.findMaxLength({0, 1, 0}), 2);
    }
}
