#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p560 {


    class Solution {
    public:
        int subarraySum(const vector<int>& nums, int k) {
            int res = 0;
            map<int, int> sumMap;
            int sum = 0;

            sumMap[sum] = 1;
            for (auto v : nums) {
                sum += v;
                int target = sum - k;

                auto it = sumMap.find(target);
                if (it != sumMap.end()) {
                    res += it->second;
                }
                sumMap[sum]++;
            }
            return res;
        }
    };

    
    TEST(LeetCode, p560) {
        Solution s;
        EXPECT_EQ(s.subarraySum({0,0,0}, 0), 6);
    }
}
