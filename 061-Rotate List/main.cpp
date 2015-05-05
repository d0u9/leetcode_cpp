//
//  main.cpp
//  leetcode-0061
//
//  Created by Douglas Su on 5/4/15.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int i = 1, j = 1;
        auto current = head, mid = head;
        for (;current->next != NULL; current = current->next, ++i) {
            if (i - j == k) {
                j++;
                mid = mid->next;
            }
        }
        if (k < i) {
            current->next = head;
            head = mid->next;
            mid->next = NULL;
        } else {
            k = k % i;
            head = rotateRight(head, k);
        }
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution *so = new Solution;
    
    vector<int> raw = {1, 2, 3, 4, 5};
    ListNode * input = NULL;
    input = new ListNode(raw[0]);
    auto current = input;
    for (int i = 1; i < 2; ++i) {
        current->next = new ListNode(raw[i]);
        current = current->next;
    }
    
    
    auto re = so->rotateRight(input, 2);
    
    cout << re << endl;
    
    return 0;
}
