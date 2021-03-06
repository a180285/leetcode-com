#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p301 {

#endif



    class Solution {
    public:
        unordered_set<string> ans;

        string inputString;
        string output;

        void dfs(int leftCount, int i, int l, int r) {
            if (l + r > inputString.size() - i) {
                return;
            }
            if (i == inputString.size()) {
                ans.insert(output);
                return;
            }
            auto c = inputString[i];
            if (c == '(') {
                if (l > 0) {
                    dfs(leftCount, i + 1, l - 1, r);
                }
                leftCount++;
            } else if (c == ')') {
                if (r > 0) {
                    dfs(leftCount, i + 1, l, r - 1);
                }
                leftCount--;
            }

            if (leftCount < 0) {
                return;
            }

            output += c;
            dfs(leftCount, i + 1, l, r);
            output.pop_back();
        }

        vector<string> removeInvalidParentheses(string s) {
            ans.clear();
            int l = 0;
            int r = 0;
            for (auto c : s) {
                if (c == '(') {
                    l++;
                } else if (c == ')') {
                    if (l > 0) {
                        l--;
                    } else {
                        r++;
                    }
                }
            }

            inputString = s;
            output = "";
            dfs(0, 0, l, r);
            return vector<string>(ans.begin(), ans.end());
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p301) {
        Solution s;
        EXPECT_EQ(s.removeInvalidParentheses(")("), vector<string>{""});
        EXPECT_EQ(s.removeInvalidParentheses(")a(b"), vector<string>{"ab"});
        EXPECT_EQ(s.removeInvalidParentheses(")a(b)"), vector<string>{"a(b)"});
//        EXPECT_EQ(s.removeInvalidParentheses("()())()"), (vector<string>){ "(())()", "()()()" });

    }
}

#endif
