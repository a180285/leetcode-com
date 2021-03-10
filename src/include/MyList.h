//
// Created by Hw on 2021/3/8.
//

#ifndef TUTORIAL_MYLIST_H
#define TUTORIAL_MYLIST_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace MyList {

    using namespace std;



    ListNode* buildList(vector<int> arr);
    void printList(ListNode* head);

    ListNode* reverseList(ListNode* head);
    int listLength(ListNode* head);
    ListNode* splitList(ListNode*& head, int n);
    ListNode* concatLists(std::initializer_list<ListNode*> lists);
    ListNode* insertNode(ListNode* it, ListNode* node);
    ListNode* getTail(ListNode* head);

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
}

#endif //TUTORIAL_MYLIST_H
