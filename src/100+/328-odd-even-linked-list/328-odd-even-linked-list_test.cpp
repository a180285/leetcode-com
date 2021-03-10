#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p328 {

#endif

    ListNode* getTail(ListNode* head) {
        while (head->next != nullptr) {
            head = head->next;
        }
        return head;
    }

    ListNode* insertNode(ListNode* it, ListNode* node) {
        if (it == nullptr) {
            return node;
        }
        if (node != nullptr) {
            node->next = it->next;
            it->next = node;
        }
        return it;
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


    class HwList {
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
        ListNode* oddEvenList(ListNode* head) {
            auto odds = make_shared<HwList>();

            auto tail = head;
            while (tail != nullptr) {
                if (tail->next == nullptr) {
                    break;
                }
                auto node = tail->next;
                tail->next = node->next;

                node->next = nullptr;
                odds->addToTail(node);
                tail = tail->next;
            }

            return concatLists({head, odds->head()});
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p328) {
        Solution s;
        printList(s.oddEvenList(buildList({1, 2, 3, 4, 5})));
    }
}

#endif
