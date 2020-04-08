#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p707 {

    struct Node {
        int val;
        Node* next;
    };

    class MyLinkedList {
    private:
        Node *dummyRoot;
        Node *tail;
        int length;
    public:
        /** Initialize your data structure here. */
        MyLinkedList() {
            dummyRoot = tail = new Node();
            length = 0;
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index) {
            if (index < 0 || index >= length) {
                return -1;
            }

            Node *cur = dummyRoot->next;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            return cur->val;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            length++;
            Node *newNode = new Node();
            newNode->val = val;
            newNode->next = dummyRoot->next;

            dummyRoot->next = newNode;
            if (tail == dummyRoot) {
                tail = newNode;
            }
        }

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            length++;
            Node *newNode = new Node();
            newNode->val = val;
            newNode->next = nullptr;

            tail->next = newNode;
            tail = newNode;
        }

        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            if (index == 0) {
                addAtHead(val);
                return;
            } else if (index == length) {
                addAtTail(val);
                return;
            } else if (index > length) {
                return;
            }
            length++;

            Node *pre, *cur;
            pre = dummyRoot;
            cur = dummyRoot->next;
            for (int i = 0; i < index; i++) {
                pre = cur;
                cur = cur->next;
            }

            Node *newNode = new Node();
            newNode->val = val;
            newNode->next = cur;

            pre->next = newNode;
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
            if (index < 0 || index >= length) {
                return;
            }
            length--;
            Node *pre, *cur;
            pre = dummyRoot;
            cur = dummyRoot->next;
            for (int i = 0; i < index; i++) {
                pre = cur;
                cur = cur->next;
            }

            pre->next = cur->next;
            if (tail == cur) {
                tail = pre;
            }
            delete cur;
        }
    };

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


    
    TEST(LeetCode, p707) {
        MyLinkedList* obj = new MyLinkedList();
//        int param_1 = obj->get(index);
//        obj->addAtHead(val);
//        obj->addAtTail(val);
//        obj->addAtIndex(index,val);
//        obj->deleteAtIndex(index);
    }
}
