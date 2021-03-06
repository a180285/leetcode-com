#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p147 {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
#endif



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
    class Solution {

    public:
        ListNode* insertionSortList(ListNode* head) {
            ListNode* newList = new ListNode();
            newList->val = INT_MIN;
            while (head != nullptr) {
                auto last = head;
                head = head->next;

                auto p = newList;
                while (p->next != nullptr && p->next->val < last->val) {
                    p = p->next;
                }

                last->next = p->next;
                p->next = last;
            }

            return newList->next;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p147) {
        Solution s;
//        EXPECT_EQ(s.numTimesAllBlue({2, 1, 3, 5, 4}), 0);
    }
}

#endif
