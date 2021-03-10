#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p61 {

#endif

    int listLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* splitList(ListNode* &head, int n) {
        ListNode* mid = head;
        if (n == 0) {
            head = nullptr;
            return mid;
        }

        n--;
        while (n > 0) {
            mid = mid->next;
            n--;
        }
        auto tmp = mid->next;
        mid->next = nullptr;
        return tmp;
    }

    ListNode* getTail(ListNode* head) {
        while (head->next != nullptr) {
            head = head->next;
        }
        return head;
    }

    ListNode* concatLists(std::initializer_list<ListNode*> lists) {
        auto* root = new ListNode();
        auto tail = root;
        for (auto head : lists) {
            tail = getTail(tail);
            tail->next = head;
        }
        auto head = root->next;
        delete root;
        return head;
    }

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
        ListNode* rotateRight(ListNode* head, int k) {
            int len = listLength(head);
            if (len == 0) {
                return head;
            }
            k %= len;
            if (k == 0) {
                return head;
            }

            auto mid = splitList(head, len - k);
            return concatLists({mid, head});
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p61) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
