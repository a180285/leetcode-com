#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p1376 {


    class Solution {
    public:
        int numOfMinutes(int n, int headID, const vector<int>& manager, const vector<int>& informTime) {
            map<int, vector<int>> edges;
            for (int i = 0; i < manager.size(); ++i) {
                edges[manager[i]].push_back(i);
            }

            return _numOfMinutes(headID, edges, informTime, 0);
        }

        int _numOfMinutes(int root, const map<int, vector<int>>& edges, const vector<int>& informTime, int now) {
            if (edges.find(root) == edges.end()) {
                return now;
            }
            now += informTime[root];
            int maxTime = now;

            for (auto& next : edges.at(root)) {
                maxTime = max(maxTime, _numOfMinutes(next, edges, informTime, now));
            }

            return maxTime;
        }
    };


    
    TEST(LeetCode, p1376) {
        Solution s;
        EXPECT_EQ(s.numOfMinutes(1, 0, {-1}, {0}), 0);
        EXPECT_EQ(s.numOfMinutes(7, 6, {1,2,3,4,5,6,-1}, {0,6,5,4,3,2,1}), 21);
        EXPECT_EQ(s.numOfMinutes(15, 0, {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6}, {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0}), 3);
    }
}
