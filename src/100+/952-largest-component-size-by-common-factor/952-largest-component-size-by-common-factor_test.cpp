#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p952 {

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
    vector<int> factors;

    void initPrimeFactor(int n) {
        factors.clear();
        factors.resize(n + 1);

        for (int i = 2; i <= n; i++) {
            if (factors[i] > 0) {
                continue;
            }
            for (int j = i; j <= n; j += i) {
                factors[j] = i;
            }
        }
    }

public:
    int largestComponentSize(vector<int>& A) {
        int maxN = 1e5 + 10;
        initPrimeFactor(maxN);
        auto dj = make_shared<DisjointSet>(A.size());

        vector<int> primeToId(maxN, -1);

        for (int i = 0; i < A.size(); i++) {
            int v = A[i];
            while (v > 1) {
                int factor = factors[v];
                while (v % factor == 0) {
                    v /= factor;
                }
                if (primeToId[factor] == -1) {
                    primeToId[factor] = i;
                }
                dj->merge(primeToId[factor], i);
            }
        }

        vector<int> setMemberCount(A.size());
        int maxCount = 1;
        for (int i = 0; i < A.size(); i++) {
            maxCount = max(maxCount, ++setMemberCount[dj->findSet(i)]);
        }

        return maxCount;
    }
};

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p952) {
        Solution s;
//        EXPECT_EQ(s.largestComponentSize(0), 0);
    }
}

#endif
