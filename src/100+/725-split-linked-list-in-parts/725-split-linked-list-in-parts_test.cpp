#ifdef HuangWei_TEST
#include <bits/stdc++.h>

#include "gtest/gtest.h"

#include "src/include/MyList.h"

using namespace std;
using namespace MyList;

namespace p725 {

#endif

    int listLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* splitList(ListNode* &head, int n) {
        ListNode* mid = head;
        if (n == 0) {
            head = nullptr;
            return mid;
        }

        n--;
        while (n > 0) {
            mid = mid->next;
            n--;
        }
        auto tmp = mid->next;
        mid->next = nullptr;
        return tmp;
    }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
    class Solution {
    public:
        vector<ListNode*> splitListToParts(ListNode* root, int k) {
            auto len = listLength(root);
            int avgLen = len / k;
            int remind = len % k;
            vector<ListNode*> ans;
            while (k--) {
                int myLen = avgLen + (remind > 0);
                remind--;
                auto nextHead = splitList(root, myLen);
                ans.push_back(root);
                root = nextHead;
            }
            return ans;
        }
    };

#ifdef HuangWei_TEST
    
    TEST(LeetCode, p725) {
        Solution s;
//        EXPECT_EQ(s.countLargestGroup(0), 0);
    }
}

#endif
