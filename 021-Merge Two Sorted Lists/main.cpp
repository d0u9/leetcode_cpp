//
//  main.cpp
//  leetcode-0021
//
//  Created by Douglas Su on 4/11/15.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *ret = NULL, *last = ret;
        while (l1 != NULL && l2 != NULL) {
            ListNode *tmp = NULL;
            if (l1->val < l2->val) {
                tmp = l1;
                l1 = l1->next;
            } else {
                tmp = l2;
                l2 = l2->next;
            }
            if (ret == NULL) {
                ret = tmp;
                last = ret;
            } else {
                last->next = tmp;
                last = last->next;
            }
            last->next = NULL;
        }
        if (l1 != NULL) {
            if (last != NULL) last->next = l1;
            else ret = l1;
        }
        if (l2 != NULL) {
            if (last != NULL) last->next = l2;
            else ret = l2;
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> L1 = {};
    vector<int> L2 = {0};
    ListNode *l1 = NULL, *l2 = NULL, *last = NULL;
    for (auto cur : L1) {
        auto *temp = new ListNode(cur);
        if (l1 == NULL) {l1 = temp; last = l1;}
        else {last->next = temp; last = last->next;}
    }
    for (auto cur : L2) {
        auto *temp = new ListNode(cur);
        if (l2 == NULL) {l2 = temp; last = l2;}
        else {last->next = temp; last = last->next;}
    }
    
    Solution *so = new Solution;
    auto re = so->mergeTwoLists(l1, l2);
    
    
    
    return 0;
}
