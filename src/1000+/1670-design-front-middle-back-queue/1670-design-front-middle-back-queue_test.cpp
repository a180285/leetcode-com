#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p1670 {

#endif



    class FrontMiddleBackQueue {
        deque<int> fq, bq;
    public:
        FrontMiddleBackQueue() {

        }

        bool empty() {
            return bq.empty() && fq.empty();
        }

        void resize() {
            // make sure fq.size == bq.size ( + 1 )
            while (fq.size() < bq.size()) {
                fq.push_back(bq.front());
                bq.pop_front();
            }
            while (fq.size() > bq.size() + 1) {
                bq.push_front(fq.back());
                fq.pop_back();
            }
        }

        void pushFront(int val) {
            fq.push_front(val);
            resize();
        }

        void pushMiddle(int val) {
            if (empty()) {
                pushFront(val);
                return;
            }

            if (fq.size() != bq.size()) {
                bq.push_front(fq.back());
                fq.pop_back();
            }
            fq.push_back(val);
            resize();
        }

        void pushBack(int val) {
            bq.push_back(val);
            resize();
        }

        int popFront() {
            if (empty()) {
                return -1;
            }
            auto ans = fq.front();
            fq.pop_front();
            resize();
            return ans;
        }

        int popMiddle() {
            if (empty()) {
                return -1;
            }
            if (bq.empty()) {
                return popFront();
            }
            auto ans = fq.back();
            fq.pop_back();
            resize();
            return ans;
        }

        int popBack() {
            if (empty()) {
                return -1;
            }

            if (bq.empty()) {
                return popFront();
            }

            auto ans = bq.back();
            bq.pop_back();
            resize();
            return ans;
        }
    };

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p1670) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
