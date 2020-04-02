#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p202 {


    class Solution {
    public:
        bool isHappy(int n) {
            set<int> loopSet;
            while (n != 1) {
                loopSet.insert(n);
                n = nextNumber(n);
                if (loopSet.find(n) != loopSet.end()) {
                    return false;
                }
            }
            return true;
        }

        int nextNumber(int n) {
            int ret = 0;
            while (n > 0) {
                auto t = n % 10;
                ret += t * t;
                n /= 10;
            }
            return ret;
        }
    };


    
    TEST(LeetCode, p202) {
        Solution s;
        EXPECT_EQ(s.isHappy(19), true);
    }
}
