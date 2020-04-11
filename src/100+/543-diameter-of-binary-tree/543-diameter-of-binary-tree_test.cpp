#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace p543 {


    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    struct Answer {
        int singlePath;
        int roundPath;
        Answer(int singlePath, int roundPath) {
            this->singlePath = singlePath;
            this->roundPath = roundPath;
        }
    };

    class Solution {
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            auto ans = _diameterOfBinaryTree(root);
            return ans.roundPath;
        }

        Answer _diameterOfBinaryTree(TreeNode* root) {
            Answer ans(-1, 0);
            if (root == nullptr) {
                return ans;
            }

            auto leftAns = _diameterOfBinaryTree(root->left);
            auto rightAns = _diameterOfBinaryTree(root->right);

            ans.singlePath = max(leftAns.singlePath, rightAns.singlePath) + 1;

            ans.roundPath = max(leftAns.roundPath, rightAns.roundPath);
            ans.roundPath = max(ans.roundPath, 2 + leftAns.singlePath + rightAns.singlePath);
            return ans;
        }
    };


    
    TEST(LeetCode, p543) {
        Solution s;
    }
}
