#include <iostream>
#include <list>

#include "gtest/gtest.h"

using namespace std;

namespace p146 {

    class LRUCache {

        struct Node {
            Node *pre, *next;
            int key, val;
        };

        int capacity;
        int length;
        Node *dummyRoot, *tail;
        map<int, Node*> _map;

        void removeNode(Node *node) {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }

        void deleteKey(int key) {
            auto it = _map.find(key);
            if (it == _map.end()) {
                return;
            }

            removeNode(it->second);
            delete it->second;

            _map.erase(it);
            this->length--;
        }

        void ejectOne() {
            deleteKey(this->dummyRoot->next->key);
        }

        void addToTail(Node *node) {
            node->next = this->tail;
            node->pre = this->tail->pre;
            node->pre->next = node;
            node->next->pre = node;
        }

    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            this->length = 0;

            this->dummyRoot = new Node();
            this->tail = new Node();
            this->dummyRoot->next = this->tail;
            this->tail->pre = this->dummyRoot;
        }

        int get(int key) {
            auto it = _map.find(key);
            if (it == _map.end()) {
                return -1;
            }

            removeNode(it->second);
            addToTail(it->second);

            return it->second->val;
        }

        void put(int key, int value) {
            if (this->capacity <= 0) {
                return;
            }
            deleteKey(key);
            if (this->length >= this->capacity) {
                ejectOne();
            }

            auto newNode = new Node();
            newNode->key = key;
            newNode->val = value;
            addToTail(newNode);
            _map[key] = newNode;
            this->length++;
        }
    };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

    
    TEST(LeetCode, p146) {
        LRUCache s(10);
    }
}
