#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/Mylist.h"

using namespace std;
using namespace MyList;

namespace p1721 {

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
        void split(ListNode* head, int n, ListNode* &pa, ListNode* &pb) {
            if (n == 0) {
                pa = nullptr;
                pb = head;
                return;
            }
            pa = head;
            pb = head;
            for (int i = 0; i < n - 1; i++) {
                pb = pb->next;
            }
            auto tmp = pb;
            pb = pb->next;
            tmp->next = nullptr;
        }

        ListNode* reverseList(ListNode* head) {
            if (head == nullptr) {
                return nullptr;
            }
            auto root = new ListNode{};
            for (auto tmpNode = head; tmpNode != nullptr; ) {
                auto nextNode = tmpNode->next;

                tmpNode->next = root->next;
                root->next = tmpNode;

                tmpNode = nextNode;
            }

            return root->next;
        }

        int length(ListNode* head) {
            int count = 0;
            while (head != nullptr) {
                count++;
                head = head->next;
            }
            return count;
        }

        ListNode* concat(ListNode* a, ListNode* b) {
            if (a == nullptr) {
                return b;
            }
            auto root = a;
            while (a->next != nullptr) {
                a = a->next;
            }
            a->next = b;
            return root;
        }


        ListNode* removeAt(ListNode* root, int k) {
            auto head = root;
            while (k > 0) {
                k--;
                head = head->next;
            }

            auto ans = head->next;
            head->next = head->next->next;
            ans->next = nullptr;
            return ans;
        }

        void insertAt(ListNode* root, int k, ListNode* node) {
            auto head = root;
            while (k > 0) {
                k--;
                head = head->next;
            }
            node->next = head->next;
            head->next = node;
        }
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            auto* root = new ListNode(0, head);

            int hn = length(head);
            if (k * 2 == hn + 1) {
                return head;
            }
            if (k * 2 > hn + 1) {
                k = hn - k + 1;
            }
            auto m1 = removeAt(root, hn - k);
            auto m2 = removeAt(root, k - 1);
            insertAt(root, k - 1, m1);
            insertAt(root, hn - k, m2);
            return root->next;
        }
    };

#ifdef HuangWei_TEST


    TEST(LeetCode, p1721) {
        Solution s;
        buildList({1, 2, 3, 4, 5, 6});
        printList(s.swapNodes(buildList({1, 2}), 1));
        printList(s.swapNodes(buildList({1, 2, 3, 4, 5, 6}), 2));

        printList(s.swapNodes(buildList({7,9,6,6,7,8,3,0,9,5}), 5));
        printList(s.swapNodes(buildList({1, 2, 3}), 2));
        printList(s.swapNodes(buildList({1, 2}), 1));


        EXPECT_EQ(s.swapNodes(buildList({1, 2, 3, 4, 5}), 2), buildList({1, 2, 3, 4, 5}));
    }
}

#endif
