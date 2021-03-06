#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p20 {

#endif

    class Solution {
    public:
        bool isValid(string s) {
            map<char, char> m;
            m[')'] = '(';
            m[']'] = '[';
            m['}'] = '{';

            stack<char> st;

            for (auto c : s) {
                if (m.count(c) == 0) {
                    st.push(c);
                } else {
                    if (st.empty()) {
                        return false;
                    }
                    if (st.top() != m[c]) {
                        return false;
                    }
                    st.pop();
                }
            }

            return st.empty();
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p20) {
        Solution s;
        EXPECT_EQ(s.isValid("()"), true);
        EXPECT_EQ(s.isValid("("), false);
        EXPECT_EQ(s.isValid(""), true);
    }
}
#endif