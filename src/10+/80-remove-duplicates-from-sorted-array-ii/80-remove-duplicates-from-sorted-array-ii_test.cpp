#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p80 {

#endif



    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() == 0) {
                return 0;
            }
            int ed = 0;
            int dn = 1;
            for (int i = 1; i < nums.size(); i++) {
                if (dn < 2 || nums[ed] != nums[i]) {
                    dn = (nums[ed] == nums[i] ? 2 : 1);
                    nums[++ed] = nums[i];
                }
            }
            return ed + 1;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p80) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
