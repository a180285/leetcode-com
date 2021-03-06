#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p90 {

#endif



    class Solution {
        vector<vector<int>> ans;
        vector<int> output;
        unordered_map<int, int> numberCount;

        void dfs(unordered_map<int, int>::iterator it) {
            if (it == numberCount.end()) {
                ans.push_back(output);
                return;
            }
            auto nextIt = it;
            nextIt++;
            dfs(nextIt);
            for (int i = 0; i < it->second; i++) {
                output.push_back(it->first);
                dfs(nextIt);
            }
            for (int i = 0; i < it->second; i++) {
                output.pop_back();
            }
        }

    public:
        vector<vector<int>>& subsetsWithDup(vector<int>& nums) {
            ans.clear();
            output.clear();
            numberCount.clear();
            for (auto num : nums) {
                numberCount[num]++;
            }
            dfs(numberCount.begin());
            return ans;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p90) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
