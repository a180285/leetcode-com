#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p876 {


    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode root(0);
            root.next = head;

            ListNode *mid, *step;
            mid = head;
            step = &root;
            while (step != nullptr) {
                step = step->next;
                if (step != nullptr) {
                    step = step->next;
                    if (step != nullptr) {
                        mid = mid->next;
                    }
                }
            }

            return mid;
        }
    };

    
    TEST(LeetCode, p876) {
        Solution s;
    }
}
