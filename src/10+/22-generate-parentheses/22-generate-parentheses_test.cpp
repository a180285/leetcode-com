#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p22 {

#endif



    class Solution {
        vector<string> ans;

        string output;

        void dfs(int l, int r) {
            if (r == 0) {
                ans.push_back(output);
                return;
            }

            if (l > 0) {
                output += '(';
                dfs(l - 1, r);
                output.pop_back();
            }
            if (r > l) {
                output += ')';
                dfs(l, r - 1);
                output.pop_back();
            }
        }
    public:
        vector<string>& generateParenthesis(int n) {
            ans.clear();
            output = "";
            dfs(n, n);
            return ans;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p22) {
        Solution s;
//        EXPECT_EQ(s.generateParenthesis(1), {"{}"});
//        EXPECT_EQ(s.generateParenthesis(2), {"{}"});
    }
}

#endif
