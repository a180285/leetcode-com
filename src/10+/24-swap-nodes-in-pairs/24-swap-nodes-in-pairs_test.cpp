#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p24 {

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
        ListNode* swapPairs(ListNode* head) {
            ListNode* newHead = new ListNode();
            auto tail = newHead;

            while (head != nullptr) {
                auto pa = head;
                auto pb = head->next;
                head = nullptr;

                if (pb != nullptr) {
                    head = pb->next;

                    pb->next = nullptr;
                    tail->next = pb;
                    tail = pb;
                }

                pa->next = nullptr;
                tail->next = pa;
                tail = pa;
            }
            return newHead->next;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p24) {
        Solution s;
//        EXPECT_EQ(s.swapPairs(0), 0);
    }
}

#endif
