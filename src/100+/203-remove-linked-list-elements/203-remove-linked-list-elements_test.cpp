#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p203 {

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


    class HwList {

        static ListNode* insertNode(ListNode* it, ListNode* node) {
            if (it == nullptr) {
                return node;
            }
            if (node != nullptr) {
                node->next = it->next;
                it->next = node;
            }
            return it;
        }

    public:
        ListNode* tail;
        ListNode* root;
        HwList() {
            root = new ListNode;
            tail = root;
        }

        void addToTail(ListNode* node) {
            tail->next = node;
            tail = tail->next;
        }

        void addToHead(ListNode* node) {
            insertNode(root, node);
        }

        ListNode* head() {
            return root->next;
        }
    };

    class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {
            auto root = HwList();
            while (head != nullptr) {
                auto newHead = head->next;
                head->next = nullptr;
                if (head->val != val) {
                    root.addToTail(head);
                }
                head = newHead;
            }
            return root.head();
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p203) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
