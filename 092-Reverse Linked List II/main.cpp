//
//  main.cpp
//  leetcode-0092
//
//  Created by Douglas Su on 5/14/15.
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
    ListNode* reverse_list(ListNode* head, ListNode*& last_one) {
        if (!head->next || !head) return head;
        ListNode* cur = head->next, *tmp = head->next;
        auto last = head, next = cur->next;
        while (tmp) {
            tmp = cur->next;
            cur->next = last;
            last = cur;
            if (next) {
                cur = next;
                next = cur->next;
            }
        }
        last_one = head;
        return cur;
    }

public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head->next || !head) return head;
        if (m == n) return head;
        ListNode *dumy_head = new ListNode(0);
        dumy_head->next = head;

        ListNode *before = NULL, *after = NULL, *cur = dumy_head;

        for (int i = 0; cur != NULL; ++i) {
            if (i == m - 1)
                before = cur;
            if (i == n)
                break;
            cur = cur->next;
        }
        after = cur->next;
        cur->next = NULL;
        ListNode *last = NULL;
        before->next = reverse_list(before->next, last);
        last->next = after;

        return dumy_head->next
        ;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> o = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(o[0]), *cur = head;
    for (int i = 1; i < o.size(); ++i) {
        cur->next = new ListNode(o[i]);
        cur = cur->next;
    }
    
    Solution *so = new Solution;
    auto re = so->reverseBetween(head, 4, 5);
    
    cout << re << endl;
    
    return 0;
}
