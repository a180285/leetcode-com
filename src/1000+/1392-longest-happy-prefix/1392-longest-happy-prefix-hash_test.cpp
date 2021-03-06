#include <iostream>
#include <bits/stdc++.h>
#include "gtest/gtest.h"

using namespace std;
typedef unsigned int uint;

namespace p1392 {


    class Solution {
    public:
        string longestPrefix(string s) {
            uint hashSum1 = 0;
            uint hashSum2 = 0;
            uint multi = 1;

            int p = 27;
            int len = 0;

            for (int i = 0; i < s.length() - 1; i++) {
                int v = s[i] - 'a';
                int reverseV = s[s.length() - 1 - i] - 'a';
                hashSum1 = hashSum1 * p + v;
                hashSum2 += reverseV * multi;
                multi *= p;

                if (hashSum1 == hashSum2) {
                    len = i + 1;
                }
            }
            return s.substr(0, len);
        }
    };


    
    TEST(LeetCode, p1392) {
        Solution s;
        EXPECT_EQ(s.longestPrefix("level"), "l");
        EXPECT_EQ(s.longestPrefix("leetcodeleet"), "leet");
        EXPECT_EQ(s.longestPrefix("a"), "");
    }
}
