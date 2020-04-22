#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p30_421 {


    class Solution {
    public:
        int countElements(const vector<int>& arr) {
            set<int> numberSet;
            for (auto v : arr) {
                numberSet.insert(v);
            }
            int ret = 0;
            for (auto v : arr) {
                ret += numberSet.count(v + 1);
            }
            return ret;
        }
    };


    
    TEST(LeetCode, p30_421) {
        Solution s;
        EXPECT_EQ(s.countElements({1, 1, 2, 3}), 3);
    }
}
