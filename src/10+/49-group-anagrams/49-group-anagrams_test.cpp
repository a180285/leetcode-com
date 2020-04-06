#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p49 {


    class Solution {
    public:
        vector<vector<string>> groupAnagrams(const vector<string> &strs) {
            map<string, vector<string>> stringMap;
            for (auto str : strs) {
                string key = str;
                sort(key.begin(), key.end());
                stringMap[key].push_back(str);
            }
            vector<vector<string>> res;
            for (auto[k, v] : stringMap) {
                res.push_back(v);
            }
            return res;
        }
    };


    TEST(LeetCode, p49) {
        Solution s;
        vector<vector<string>> res = {
                { "bat" },
                { "eat", "tea", "ate" },
                { "tan", "nat" }
        };
        EXPECT_EQ(s.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}), res);
    }
}
