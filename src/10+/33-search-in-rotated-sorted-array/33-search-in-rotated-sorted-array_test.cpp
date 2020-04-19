#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p33 {


    class Solution {
        int findStart(const vector<int>& nums) {
            int low = 0;
            int high = nums.size() - 1;
            if (nums[low] < nums[high]) {
                return 0;
            }

            while (low < high) { // nums[high] < nums[0]
                int mid = (low + high) / 2;
                if (nums[mid] < nums[0]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return high;
        }
    public:
        int search(const vector<int>& nums, int target) {
            if (nums.empty()) {
                return -1;
            }
            int start = findStart(nums);
            int low = 0;
            int high = nums.size() - 1;
            while (low < high) { // nums[low + start] <= target
                int mid = (low + high + 1) / 2;
                if (nums[(mid + start) % nums.size()] <= target) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            int index = (low + start) % nums.size();
            if (nums[index] == target) {
                return index;
            } else {
                return -1;
            }
        }
    };

    
    TEST(LeetCode, p33) {
        Solution s;
        EXPECT_EQ(s.search({4,5,6,7,0,1,2}, 0), 4);
        EXPECT_EQ(s.search({4,5,6,7,0,1,2}, 3), -1);
        EXPECT_EQ(s.search({0,1,2,4,5,6,7}, 3), -1);
        EXPECT_EQ(s.search({0,1,2,4,5,6,7}, 0), 0);
        EXPECT_EQ(s.search({0}, 0), 0);
        EXPECT_EQ(s.search({0}, 1), -1);
    }
}
