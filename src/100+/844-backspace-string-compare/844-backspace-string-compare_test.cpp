#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p844 {


    class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            int si = S.length() - 1;
            int ti = T.length() - 1;
            while (si >= 0 || ti >= 0) {
                char c1 = getNextChar(S, si);
                char c2 = getNextChar(T, ti);
                if (c1 != c2) {
                    return false;
                }
            }
            return true;
        }

        char getNextChar(const string& s, int& i) {
            int cnt = 0;
            for (; i >= 0; i--) {
                if (s[i] == '#') {
                    cnt++;
                } else if (cnt > 0) {
                    cnt--;
                } else {
                    i--;
                    return s[i + 1];
                }
            }

            return 0;
        }
    };

    
    TEST(LeetCode, p844) {
        Solution s;
        EXPECT_EQ(s.backspaceCompare("a##c", "#a#c"), true);
        EXPECT_EQ(s.backspaceCompare("ab##", "c#d#"), true);
        EXPECT_EQ(s.backspaceCompare("ab##d", "c#d#"), false);
    }
}
