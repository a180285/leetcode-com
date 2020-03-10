#include <iostream>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        string result = "a";
        char nextChar = 'a';
        if (n % 2 == 0) {
            nextChar = 'b';
        }
        for (int i = 1; i < n; i++) {
            result += nextChar;
        }
        return result;
    }
};

TEST(LeetCode, p1374) {
    Solution s;
    EXPECT_EQ(s.generateTheString(10), "abbbbbbbbb");
}
