#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

using namespace std;

namespace p148 {
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
        ListNode* listPool[64];
        ListNode* m_head = new ListNode();

        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            m_head->next = nullptr;
            ListNode* tail = m_head;
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
            return m_head->next;
        }

    public:
        ListNode* sortList(ListNode* head) {
            while (head != nullptr) {
                auto last = head;
                head = head->next;
                last->next = nullptr;

                for (auto & l : listPool) {
                    if (l == nullptr) {
                        l = last;
                        break;
                    }
                    last = mergeTwoLists(last, l);
                    l = nullptr;
                }
            }
            ListNode* newList = nullptr;
            for (auto & l : listPool) {
                if (l != nullptr) {
                    newList = mergeTwoLists(newList, l);
                }
            }
            return newList;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p148) {
        Solution s;
//        EXPECT_EQ(s.numTimesAllBlue({2, 1, 3, 5, 4}), 0);
    }
}

#endif
