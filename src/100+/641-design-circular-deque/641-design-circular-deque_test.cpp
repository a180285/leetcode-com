#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p641 {

#endif



    class MyCircularDeque {
        vector<int> v;
        int n;
        int st, ed;
        bool full;

        void myMove(int &p) {
            p = (p + 1) % n;
        }

        void myMoveBack(int &p) {
            p = (p + n - 1) % n;
        }

    public:
        /** Initialize your data structure here. Set the size of the deque to be k. */
        MyCircularDeque(int k) {
            n = k;
            v.resize(k);
            st = ed = 0;
            full = false;
        }

        /** Adds an item at the front of Deque. Return true if the operation is successful. */
        bool insertFront(int value) {
            if (isFull()) {
                return false;
            }
            myMoveBack(st);
            v[st] = value;
            full = (st == ed);
            return true;
        }

        /** Adds an item at the rear of Deque. Return true if the operation is successful. */
        bool insertLast(int value) {
            if (isFull()) {
                return false;
            }
            v[ed] = value;
            myMove(ed);
            full = (st == ed);
            return true;
        }

        /** Deletes an item from the front of Deque. Return true if the operation is successful. */
        bool deleteFront() {
            if (isEmpty()) {
                return false;
            }

            myMove(st);
            full = false;
            return true;
        }

        /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
        bool deleteLast() {
            if (isEmpty()) {
                return false;
            }

            myMoveBack(ed);
            full = false;

            return true;
        }

        /** Get the front item from the deque. */
        int getFront() {
            if (isEmpty()) {
                return -1;
            }
            return v[st];
        }

        /** Get the last item from the deque. */
        int getRear() {
            if (isEmpty()) {
                return -1;
            }
            return v[(ed + n - 1) % n];
        }

        bool isEmpty() {
            return (n == 0) || ((!full) && st == ed);
        }

        bool isFull() {
            return (n == 0) || full;
        }

    };

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p641) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
