//
//  main.cpp
//  leetcode-0020
//
//  Created by Douglas Su on 4/11/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) return head;
        auto a = head, b = head->next, c = head;
        if (b == NULL) return head;
        for (; a != NULL && b != NULL;) {
            if (a == head) head = b;
            else c->next = b;
            
            a->next = b->next;
            b->next = a;
            auto tmp = a;
            a = b;
            b = tmp;
            c = b;
            if (b ->next == NULL || b ->next->next == NULL) break;
            
            a = b->next;
            b = b->next->next;
            
        }
        
        return head;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    ListNode * input = NULL, *last = input;
    vector<int> k = {1};
    for (int i = 0; i < k.size(); ++i) {
        if (i == 0) {
            input = new ListNode(k[i]);
            last = input;
        }
        else {
            last->next = new ListNode(k[i]);
            last = last->next;
        }
    }
    
    Solution * so = new Solution;
    auto re = so->swapPairs(input);
    
    cout << re << endl;
    
    return 0;
}
