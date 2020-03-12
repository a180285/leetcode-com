#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p218 {


    class Solution {
    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
            sort(buildings.begin(), buildings.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
                if (a[0] != b[0]) {
                    return a[0] < b[0];
                } else {
                    return a[2] > b[2];
                }
            });

            map<int, int64_t> edgeMap; // height -> right
            edgeMap[0] = LLONG_MAX;

            vector<vector<int>> keyPoints;
            for (auto& building : buildings) {
                int left = building[0];
                int right = building[1];
                int height = building[2];
                // add key points
                for (auto it = edgeMap.rbegin(), nextIt = it; it != edgeMap.rend(); it = nextIt) {
                    nextIt++;

                    if (it->second >= left) {
                        break;
                    }
                    int nextHeight = nextIt->first;
                    keyPoints.push_back({int(it->second), nextHeight});

                    nextIt = make_reverse_iterator(edgeMap.erase(nextIt.base()));
                }

                // remove edge
                for (auto it = make_reverse_iterator(edgeMap.lower_bound(height)), nextIt = it; it != edgeMap.rend(); it = nextIt) {
                    nextIt++;
                    if (it->second > right) {
                        break;
                    }
                    nextIt = make_reverse_iterator(edgeMap.erase(nextIt.base()));
                }

                if (edgeMap.rbegin()->first < height) {
                    keyPoints.push_back({left, height});
                }
                if (edgeMap.lower_bound(height) == edgeMap.end() || edgeMap.lower_bound(height)->second < right) {
                    edgeMap[height] = right;
                }
            }

            for (auto it = edgeMap.rbegin(), nextIt = it; it != edgeMap.rend(); it = nextIt) {
                nextIt++;

                if (it->first == 0) {
                    break;
                }

                int nextHeight = nextIt->first;
                keyPoints.push_back({int(it->second), nextHeight});
            }

            return keyPoints;
        }
    };

    
    TEST(LeetCode, p218) {
        Solution s;

        vector<vector<int>> input = {
                {2,9,10},
                {3,7,15},
                {5,12,12},
                {15,20,10},
                {19,24,8}};

        vector<vector<int>> output = {
                {2, 10},
                {3, 15},
                {7, 12},
                {12, 0},
                {15, 10},
                {20, 8},
                {24, 0}
        };

        vector<vector<int>> input2 = {
                {0,2147483647,2147483647}
        };
        vector<vector<int>> output2 = {
                {0,2147483647},
                {2147483647,0},
        };


        vector<vector<int>> input3 = {
                {0,2,3},{2,5,3}
        };
        vector<vector<int>> output3 = {
                {0,3},
                {5,0},
        };

        vector<vector<int>> input4 = {
                {1,2,1},
                {1,2,2},
                {1,2,3},
        };
        vector<vector<int>> output4 = {
                {1,3},
                {2,0},
        };

        vector<vector<int>> input5 = {
                {1,2,2},
                {2,4,3},
        };
        vector<vector<int>> output5 = {
                {1,2},
                {2,3},
                {4,0},
        };

        vector<vector<int>> input6 = {{6765,184288,53874},{13769,607194,451649},{43325,568099,982005},{47356,933141,123943},{59810,561434,119381},{75382,594625,738524},{111895,617442,587304},{143767,869128,471633},{195676,285251,107127},{218793,772827,229219},{316837,802148,899966},{329669,790525,416754},{364886,882642,535852},{368825,651379,6209},{382318,992082,300642},{397203,478094,436894},{436174,442141,612149},{502967,704582,918199},{503084,561197,625737},{533311,958802,705998},{565945,674881,149834},{615397,704261,746064},{624917,909316,831007},{788731,924868,633726},{791965,912123,438310}};
        vector<vector<int>> output6 = {{6765,53874},{13769,451649},{43325,982005},{568099,918199},{704582,899966},{802148,831007},{909316,705998},{958802,300642},{992082,0}};

        EXPECT_EQ(s.getSkyline(input), output);
        EXPECT_EQ(s.getSkyline(input2), output2);
        EXPECT_EQ(s.getSkyline(input3), output3);
        EXPECT_EQ(s.getSkyline(input4), output4);
        EXPECT_EQ(s.getSkyline(input5), output5);
        EXPECT_EQ(s.getSkyline(input6), output6);
    }
}
