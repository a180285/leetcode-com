#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p26 {

#endif



    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() == 0) {
                return 0;
            }
            int ed = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[ed] != nums[i]) {
                    nums[++ed] = nums[i];
                }
            }
            return ed + 1;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p26) {
        Solution s;
//        EXPECT_EQ(s.removeDuplicates(0), 0);
    }
}

#endif
