#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p1627 {

#endif


    class DisjointSet {
        vector<int> f;
    public:
        DisjointSet(int n) {
            f.resize(n);
            for (int i = 0; i < n; i++) {
                f[i] = i;
            }
        }

        int findSet(int x) {
            if (f[x] == x) {
                return x;
            }
            f[x] = findSet(f[x]);
            return f[x];
        }

        void merge(int a, int b) {
            f[findSet(a)] = f[findSet(b)];
        }

        bool isSameSet(int a, int b) {
            return findSet(a) == findSet(b);
        }
    };


    class Solution {
        vector<bool> ans;
    public:
        vector<bool>& areConnected(int n, int threshold, vector<vector<int>>& queries) {
            auto dj = make_shared<DisjointSet>(n + 1);

            for (int i = threshold + 1; i <= n; i++) {
                for (int j = i + i; j <= n; j += i) {
                    dj->merge(i, j);
                }
            }

            for (auto &q : queries) {
                ans.push_back(dj->isSameSet(q[0], q[1]));
            }

            return ans;
        }
    };


#ifdef HuangWei_TEST
    
    TEST(LeetCode, p1627) {
        Solution s;
//        EXPECT_EQ(s.areConnected(0), 0);
    }
}

#endif
