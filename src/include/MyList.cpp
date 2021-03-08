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

}
