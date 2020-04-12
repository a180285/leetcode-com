#include <iostream>
#include <queue>

#include "gtest/gtest.h"

using namespace std;

namespace p1046 {


    class Solution {
    public:
        int lastStoneWeight(const vector<int>& stones) {
            priority_queue<int> s(stones.begin(), stones.end());
            s.push(0);
            s.push(0);
            while (true) {
                auto s1 = s.top();
                s.pop();
                auto s2 = s.top();
                s.pop();
                if (s2 == 0) {
                    return s1;
                }
                s.push(s1 - s2);
            }
        }
    };

    
    TEST(LeetCode, p1046) {
        Solution s;
        EXPECT_EQ(s.lastStoneWeight({2,7,4,1,8,1}), 1);
        EXPECT_EQ(s.lastStoneWeight({8, 4, 4}), 0);
    }
}
