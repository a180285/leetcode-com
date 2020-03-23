#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p1392_kmp {


    class Solution {
    public:
        string longestPrefix(string s) {
            vector<int> kmp = vector<int>(s.length() + 10);
            kmp[0] = -1;
            for (int i = 1; i < s.length(); i++) {
                int k = kmp[i - 1];
                while (true) {
                    if (s[i] == s[k + 1]) {
                        kmp[i] = k + 1;
                        break;
                    }
                    if (k == -1) {
                        kmp[i] = k;
                        break;
                    }
                    k = kmp[k];
                }
            }

            return s.substr(0, kmp[s.length() - 1] + 1);
        }
    };


    
    TEST(LeetCode, p1392_kmp) {
        Solution s;
        EXPECT_EQ(s.longestPrefix("level"), "l");
        EXPECT_EQ(s.longestPrefix("leetcodeleet"), "leet");
        EXPECT_EQ(s.longestPrefix("a"), "");
    }
}
