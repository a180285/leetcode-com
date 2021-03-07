#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p899 {

#endif


    class Solution {
        string ans;
        unordered_set<string> strings;

        void bfs(const string& s, int k) {
            queue<string> q;
            q.push(s);
            while (!q.empty()) {
                auto now = q.front();
                q.pop();

                for (int i = 0; i < k; i++) {
                    auto newS = now.substr(0, i) + now.substr(i + 1, now.size() - i - 1) + now[i];
                    if (strings.count(newS) > 0) {
                        continue;
                    }
                    strings.insert(newS);
                    ans = min(ans, newS);
                    q.push(newS);
                }
            }
        }

        string minimalRepresentationString(string sec) {
            int n = sec.size();
            int k = 0, i = 0, j = 1;
            while (k < n && i < n && j < n) {
                if (sec[(i + k) % n] == sec[(j + k) % n]) {
                    k++;
                } else {
                    sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
                    if (i == j) i++;
                    k = 0;
                }
            }
            i = min(i, j);
            if (i == 0) {
                return sec;
            }
            return sec.substr(i) + sec.substr(0, i);
        }

    public:
        string orderlyQueue(string s, int k) {
            if (k == 1) {
                return minimalRepresentationString(s);
            } else {
                sort(s.begin(), s.end());
                return s;
            }
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p899) {
        Solution s;
        EXPECT_EQ(s.orderlyQueue("gfedcba", 2), "");
        EXPECT_EQ(s.orderlyQueue("gfedcba", 1), "");
        EXPECT_EQ(s.orderlyQueue("owikhase", 2), "");
        EXPECT_EQ(s.orderlyQueue("owirkhase", 2), "");
        EXPECT_EQ(s.orderlyQueue("owirkhasge", 2), "");
        EXPECT_EQ(s.orderlyQueue("owirkhasdge", 2), "");


    }
}

#endif
