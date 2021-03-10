#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p622 {

#endif



    class MyCircularQueue {
        vector<int> v;
        int n;
        int st, ed;
        bool full;

        void myMove(int &p) {
            p = (p + 1) % n;
        }

    public:
        MyCircularQueue(int k) {
            n = k;
            v.resize(k);
            st = ed = 0;
            full = false;
        }

        bool enQueue(int value) {
            if (isFull()) {
                return false;
            }
            v[ed] = value;
            myMove(ed);
            full = (st == ed);
            return true;
        }

        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            myMove(st);
            full = false;
            return true;
        }

        int Front() {
            if (isEmpty()) {
                return -1;
            }
            return v[st];
        }

        int Rear() {
            if (isEmpty()) {
                return -1;
            }

            return v[(ed + n - 1) % n];
        }

        bool isEmpty() {
            return (!full) && st == ed;
        }

        bool isFull() {
            return full;
        }
    };

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p622) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
