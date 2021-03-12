#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p138 {
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };
#endif



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

    class Solution {
    public:
        Node* copyRandomList(Node* head) {
            auto orgHead = head;
            while (head != nullptr) {
                auto newNode = new Node(head->val);
                newNode->random = head->random;
                newNode->next = head->next;
                head->next = newNode;
                head = newNode->next;
            }

            head = orgHead;
            while (head != nullptr) {
                head = head->next;
                if (head->random != nullptr) {
                    head->random = head->random->next;
                }
                head = head->next;
            }

            auto root = new Node(0);
            auto tail = root;

            head = orgHead;
            while (head != nullptr) {
                auto oldHead = head;

                head = head->next;
                tail->next = head;
                tail = tail->next;
                head = head->next;

                oldHead->next = head;
            }

            return root->next;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p138) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
