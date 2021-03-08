#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p92 {

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
        ListNode *root, *mid, *tail;

        void addToTail(ListNode *node) {
            mid = tail;
            tail->next = node;
            tail = tail->next;
        }

        void addToMid(ListNode *node) {
            node->next = mid->next;
            mid->next = node;
        }

    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            root = new ListNode;
            tail = root;
            mid = root;

            while (head != nullptr) {
                left--;
                right--;
                auto tmp = head;
                head = head->next;
                tmp->next = nullptr;
                if (left >= 0) {
                    addToTail(tmp);
                } else if (right >= 0) {
                    addToMid(tmp);
                } else {
                    addToTail(tmp);
                }
            }
            return root->next;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p92) {
        Solution s;
        printList(s.reverseBetween(buildList({1, 2, 3, 4, 5}), 2, 4));
        EXPECT_EQ(1, 0);
    }
}

#endif
