#include <iostream>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int numTimesAllBlue(const vector<int>& light) {
        int cnt = 0;
        int maxVal = -1;

        for (int i = 0; i < light.size(); i++) {
            int lightId = light[i];
            maxVal = max(maxVal, lightId);
            if (maxVal == i + 1) {
                cnt++;
            }
        }
        return cnt;
    }
};

TEST(LeetCode, p1375) {
    Solution s;
    EXPECT_EQ(s.numTimesAllBlue({2,1,3,5,4}), 3);
}
