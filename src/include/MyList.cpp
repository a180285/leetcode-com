#include <bits/stdc++.h>
#include "MyList.h"

namespace MyList {

    using namespace std;

    ListNode* buildList(vector<int> arr) {
        ListNode* root = new ListNode;
        ListNode* tail = root;
        for (auto v : arr) {
            auto newNode = new ListNode(v);
            tail->next = newNode;
            tail = tail->next;
        }
        return root->next;
    }

    void printList(ListNode* head) {
        while (head != nullptr) {
            printf("%d ", head->val);
            head = head->next;
        }
        puts("");
    }

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

}
