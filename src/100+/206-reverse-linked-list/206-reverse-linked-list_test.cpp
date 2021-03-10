#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p206 {

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
        ListNode* reverseList(ListNode* head) {
            ListNode* root = new ListNode;
            while (head != nullptr) {
                auto node = head;
                head = head->next;
                node->next = root->next;
                root->next = node;
            }
            head = root->next;
            delete root;
            return head;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p206) {
        Solution s;
//        EXPECT_EQ(s.reverseList(0), 0);
    }
}

#endif
