#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p200 {


    class Solution {
        int r, c;
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1,-1, 0,  0};
        void visit(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
            if (x < 0 || x >= r || y < 0 || y >= c) {
                return;
            }
            if (visited[x][y] || grid[x][y] == '0') {
                return;
            }
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                visit(grid, visited, tx, ty);
            }
        }
    public:
        int numIslands(const vector<vector<char>>& grid) {
            r = grid.size();
            if (r == 0) {
                return 0;
            }
            c = grid[0].size();
            if (c == 0) {
                return 0;
            }

            vector<vector<bool>> visited(r, vector<bool>(c));

            int islands = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (!visited[i][j] && grid[i][j] == '1') {
                        islands++;
                        visit(grid, visited, i, j);
                    }
                }
            }
            return islands;
        }
    };

    
    TEST(LeetCode, p200) {
        Solution s;
        EXPECT_EQ(s.numIslands({
                                       {'1', '1', '0', '0', '0'},
                                       {'1', '1', '0', '0', '0'},
                                       {'0', '0', '1', '0', '0'},
                                       {'0', '0', '0', '1', '1'},
                                       {'0', '0', '0', '1', '1'},
        }), 3);
    }
}
