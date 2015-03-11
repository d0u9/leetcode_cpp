//
//  main.cpp
//  leetcode-0002
//
//  Created by Douglas Su on 3/11/15.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2)
            return nullptr;
        auto c1 = l1, c2 = l2, tmp = l1;
        ListNode * re = nullptr, *last = nullptr, *current = nullptr;
        int carry = 0;
        int digit = 0;
        int A = 0;
        int B = 0;
        
        while ((c1 || c2) || carry) {
            A = (!c1) ? 0 : c1->val;
            B = (!c2) ? 0 : c2->val;
            
            auto sum = A + B + carry;
            carry = sum / 10;
            digit = sum % 10;
            if (!re) {
                re = new ListNode(digit);
                last = re;
            } else {
                current = new ListNode(digit);
                last->next = current;
                last = current;
            }
            
            tmp = c1;
            c1 = (c1) ? tmp->next : nullptr;
            delete tmp;
            tmp = c2;
            c2 = (c2) ? tmp->next : nullptr;
            delete tmp;
        }
        
        
        return re;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ListNode *input1 = nullptr, *input2 = nullptr;
    ListNode *current = nullptr, *last = nullptr;
    
    vector<int> input_1 = {5};
    vector<int> input_2 = {5};
    
    for (auto i : input_1) {
        if (!input1) {
            input1 = new ListNode(i);
            last = input1;
        } else {
            current = new ListNode(i);
            last->next = current;
            last = current;
        }
    }
    
    for (auto i : input_2) {
        if (!input2) {
            input2 = new ListNode(i);
            last = input2;
        } else {
            current = new ListNode(i);
            last->next = current;
            last = current;
        }
    }
    
    Solution *so = new Solution;
    ListNode * result = so->addTwoNumbers(input1, input2);
    
    
    return 0;
}
