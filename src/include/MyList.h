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
}

#endif //TUTORIAL_MYLIST_H
