#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p21 {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

#endif




    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* head = new ListNode();
            ListNode* tail = head;
            while (l1 != nullptr || l2 != nullptr) {
                if (l1 == nullptr) {
                    tail->next = l2;
                    break;
                }
                if (l2 == nullptr) {
                    tail->next = l1;
                    break;
                }
                if (l1->val > l2->val) {
                    swap(l1, l2);
                }
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
            return head->next;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p21) {
        Solution s;
//        EXPECT_EQ(s.mergeTwoLists({2, 1, 3, 5, 4}), 0);
    }
}

#endif
