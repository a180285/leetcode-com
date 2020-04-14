#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p30_414 {


    class Solution {
    public:
        string stringShift(string s, const vector<vector<int>>& shift) {
            int startId = 0;
            int length = s.length();
            for (auto& oneShift : shift) {
                int step = oneShift[1] % length;
                if (oneShift[0] == 1) {
                    step = length - step;
                }
                startId = (startId + step) % length;
            }
            return s.substr(startId, length - startId) + s.substr(0, startId);
        }
    };


    
    TEST(LeetCode, p30_414) {
        Solution s;
        EXPECT_EQ(s.stringShift("abc", {{0, 1}, {1, 2}}), "cab");
    }
}
