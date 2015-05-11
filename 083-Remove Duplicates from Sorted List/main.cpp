//
//  main.cpp
//  leetcode-0083
//
//  Created by Douglas Su on 5/11/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *cur = head->next, *new_end = head;
        while (cur) {
            if (cur->val == new_end->val) {
                new_end->next = cur->next;
                cur = cur->next;
            } else {
                new_end = new_end->next;
                new_end->val = cur->val;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    return 0;
}
