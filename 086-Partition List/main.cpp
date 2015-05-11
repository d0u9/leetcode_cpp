//
//  main.cpp
//  leetcode-0086
//
//  Created by Douglas Su on 5/11/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode *less = new ListNode(0), *great_or_equal = new ListNode(0), *cur = head;
        ListNode *l_cur = less, *g_cur = great_or_equal;
        while (cur) {
            if (cur->val < x) {
                l_cur->next = cur;
                l_cur = l_cur->next;
            } else {
                g_cur->next = cur;
                g_cur = g_cur->next;
            }
            cur = cur->next;
        }
        g_cur->next = NULL;
        l_cur->next = great_or_equal->next;
        return less->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *input = new ListNode(1);
    vector<int> o = {1, 1};
    for (int i = 1; i < o.size(); ++i) {
        input->next = new ListNode(o[i]);
    }
    
    Solution *so = new Solution;
    auto re = so->partition(input, 2);
    cout << re << endl;
    return 0;
}
