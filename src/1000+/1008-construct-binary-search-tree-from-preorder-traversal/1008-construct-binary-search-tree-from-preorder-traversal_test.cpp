#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p1008 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
        TreeNode *build(const vector<int>::const_iterator preorderStart,
                        const vector<int>::const_iterator preorderEnd,
                        const vector<int>::const_iterator inorderStart,
                        const vector<int>::const_iterator inorderEnd) {
            if (preorderStart == preorderEnd) {
                return nullptr;
            }
            TreeNode *root = new TreeNode(*preorderStart);
            auto it = find(inorderStart, inorderEnd, root->val);
            auto length = it - inorderStart;
            auto preorderLeftBegin = preorderStart + 1;
            root->left = build(preorderLeftBegin, preorderLeftBegin + length,
                  inorderStart, inorderStart + length);
            auto preorderRightBegin = preorderStart + length + 1;
            root->right = build(preorderRightBegin, preorderEnd,
                    it + 1, inorderEnd);
            return root;
        }

    public:
        TreeNode *bstFromPreorder(const vector<int> &preorder) {
            vector<int> inOrder(preorder);
            sort(inOrder.begin(), inOrder.end());
            return build(preorder.begin(), preorder.end(), inOrder.begin(), inOrder.end());
        }
    };


    TEST(LeetCode, p1008) {
        Solution s;
//        EXPECT_EQ(s.bstFromPreorder({2, 1, 3, 5, 4}), nullptr);
    }
}
