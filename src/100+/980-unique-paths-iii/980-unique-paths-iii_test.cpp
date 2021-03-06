#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p980 {

#endif

int dx[] = {1, -1, 0, 0};
int dy[] = {0,  0, 1,-1};

    class Solution {
        int r, c;

        int encode(int x, int y) const {
            return x * c + y;
        }

        void decode(int v, int& x, int& y) const {
            x = v / c;
            y = v % c;
        }

    public:
        int uniquePathsIII(vector<vector<int>>& grid) {
            r = grid.size();
            c = grid[0].size();

            int st;
            int ed;
            int totalMask = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == -1) {
                        continue;
                    }
                    if (grid[i][j] == 1) {
                        st = encode(i, j);
                    }
                    if (grid[i][j] == 2) {
                        ed = encode(i, j);
                    }
                    grid[i][j] = 0;
                    totalMask |= 1 << encode(i, j);
                }
            }

            queue<int> nextNodes;
            unordered_set<int> visitFlags[r * c];
            vector<int> visitCount[r * c];
            vector<bool> inQ(r * c);

            for (int i = 0; i < r * c; i++) {
                visitCount[i].resize(1 << (r * c));
            }

            nextNodes.push(st);
            visitFlags[st].insert(1 << st);
            visitCount[st][1 << st] = 1;

            while (!nextNodes.empty()) {
                int nowId = nextNodes.front();
                nextNodes.pop();
                if (nowId == ed) {
                    continue;
                }
                int sx, sy;
                decode(nowId, sx, sy);
                inQ[nowId] = false;

                for (int startFlag : visitFlags[nowId]) {
                    int nowCount = visitCount[nowId][startFlag];
                    for (int dir = 0; dir < 4; dir++) {
                        int tx = sx + dx[dir];
                        int ty = sy + dy[dir];
                        if (tx < 0 || tx >= r || ty < 0 || ty >= c || grid[tx][ty] == -1) {
                            continue;
                        }
                        int tid = encode(tx, ty);
                        int newFlag = (startFlag | (1 << tid));
                        if (startFlag == newFlag) {
                            continue;
                        }
                        if (!inQ[tid]) {
                            nextNodes.push(tid);
                        }
                        visitFlags[tid].insert(newFlag);
                        visitCount[tid][newFlag] += nowCount;
                    }
                }
                visitFlags[nowId].clear();
            }
            return visitCount[ed][totalMask];
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p980) {
        vector<vector<int>> totalMap = {
                {1, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 2},
        };

        Solution s;
        EXPECT_EQ(s.uniquePathsIII(totalMap), 0);
    }
}

#endif
