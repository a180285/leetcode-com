#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p1206 {

    class Skiplist {
    private:
        struct Node {
            int val;
            Node *next;
            Node *down;

            Node() {
                val = 0;
                next = nullptr;
                down = nullptr;
            }
        };

        vector<Node*> lists;
        vector<int> lengths;
        const int levels = 20;

    public:
        Skiplist() {
            lengths.resize(levels, 0);
            lists.resize(levels, nullptr);
            for (int i = 0; i < levels; i++) {
                lists[i] = new Node();
            }
            for (int i = 0; i+1 < levels; i++) {
                lists[i]->down = lists[i + 1];
            }
        }

        bool search(int target) {
            Node *cur = lists[0];
            while (cur->down != nullptr) {
                cur = cur->down;
                while (cur->next != nullptr && cur->next->val < target) {
                    cur = cur->next;
                }
            }
            return cur->next != nullptr && cur->next->val == target;
        }

        void add(int num) {
            insert(0, lists[0], num);
        }

        Node* insert(int level, Node* cur, int val) {
            while (cur->next != nullptr && cur->next->val < val) {
                cur = cur->next;
            }
            if (cur->down == nullptr) { // last level
                Node *newNode = new Node();
                newNode->next = cur->next;
                newNode->val = val;

                cur->next = newNode;

                lengths[level]++;
                return newNode;
            }

            auto nextLevelNode = insert(level + 1, cur->down, val);
            if (nextLevelNode != nullptr && lengths[level] * 2 < lengths[level + 1]) {
                Node *newNode = new Node();
                newNode->next = cur->next;
                newNode->val = val;
                newNode->down = nextLevelNode;

                cur->next = newNode;

                lengths[level]++;
                return newNode;
            }
            return nullptr;
        }

        bool erase(int num) {
            return remove(0, lists[0], num) != nullptr;
        }

        Node* remove(int level, Node* cur, int val) {
            while (cur->next != nullptr && cur->next->val < val) {
                cur = cur->next;
            }

            if (cur->down == nullptr) { // last level
                Node* deletedNode = nullptr;
                if (cur->next != nullptr && cur->next->val == val) {
                    lengths[level]--;
                    deletedNode = cur->next;
                    cur->next = cur->next->next;
                    delete deletedNode;
                }
                return deletedNode;
            }

            auto deletedNode = remove(level + 1, cur->down, val);
            if (cur->next != nullptr && cur->next->down == deletedNode) {
                lengths[level]--;
                deletedNode = cur->next;
                cur->next = cur->next->next;
                delete deletedNode;
            }
            return deletedNode;
        }
    };

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

    
    TEST(LeetCode, p1206) {
        Skiplist* obj = new Skiplist();
    }
}
