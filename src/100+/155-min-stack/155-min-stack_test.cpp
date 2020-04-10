#include <iostream>
#include <stack>                                          // For stack<T> container

#include "gtest/gtest.h"

using namespace std;

namespace p155 {


    class MinStack {
        struct Node {
            int val;
            int min;

            Node(int val, int min) {
                this->val = val;
                this->min = min;
            }
        };
    public:

        stack<Node> _stack;
        /** initialize your data structure here. */
        MinStack() {

        }

        void push(int x) {
            int myMin = x;
            if (!_stack.empty()) {
                myMin = min(myMin, _stack.top().min);
            }
            _stack.push(Node(x, myMin));
        }

        void pop() {
            _stack.pop();
        }

        int top() {
            return _stack.top().val;
        }

        int getMin() {
            return _stack.top().min;
        }
    };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


    
    TEST(LeetCode, p155) {
        MinStack* obj = new MinStack();
    }
}
