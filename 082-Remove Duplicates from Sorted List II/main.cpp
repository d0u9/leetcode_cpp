//
//  main.cpp
//  leetcode-0001
//
//  Created by Douglas Su on 3/2/15.
//  Copyright (c) 2015 Douglas Su. All rights reserved.
//

#include <iostream>
#include <cstdint>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/******************************************/
class Solution {
public:
    struct RecordNode {
        uint32_t    bitmap;
        RecordNode() : bitmap(0) {}
    };
    
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        
#define ZONE_PER_BLOCK  (32 / 2)
        RecordNode *positive_bitmap = new RecordNode[50], *negative_bitmap = new RecordNode[50], *current_bitmap = NULL;
        
        ListNode *current = head, *last = NULL;
        
        int offset = 0, block = 0;
        
        while (current) {
            
            if (current->val >= 0) {
                int value = current->val;
                block = value / ZONE_PER_BLOCK;
                offset = value % ZONE_PER_BLOCK;
                current_bitmap = positive_bitmap + block * sizeof(RecordNode);
            } else {
                int value = 0 - current->val;
                block = value / ZONE_PER_BLOCK;
                offset = value % ZONE_PER_BLOCK;
                current_bitmap = negative_bitmap + block * sizeof(RecordNode);
            }
            
            if ((1LL << (offset * 2)) & current_bitmap->bitmap) {
                //Have added this number
                current_bitmap->bitmap |= (1LL << (offset * 2 + 1));
            } else {
                current_bitmap->bitmap |= (1LL << (offset * 2));
            }
            
            current = current->next;
        }
        
        current = last = head;
        while (current) {
            
            if (current->val >= 0) {
                int value = current->val;
                block = value / ZONE_PER_BLOCK;
                offset = value % ZONE_PER_BLOCK;
                current_bitmap = positive_bitmap + block * sizeof(RecordNode);
            } else {
                int value = 0 - current->val;
                block = value / ZONE_PER_BLOCK;
                offset = value % ZONE_PER_BLOCK;
                current_bitmap = negative_bitmap + block * sizeof(RecordNode);
            }
            
            if ((1LL << (offset * 2 + 1)) & current_bitmap->bitmap) {
                //Dumplicated elements
                if (current == head) {
                    head = current->next;
                    delete current;
                    current = head;
                    continue;
                } else {
                    last->next = current->next;
                    delete current;
                    current = last->next;
                    continue;
                }
            } else {
                last = current;
                current = current->next;
            }
        }

        
        return head;
    }
};
/******************************************/

int main(int argc, char const* argv[])
{
    int value = 0;
    ListNode * head = NULL;
    ListNode * current = NULL;
    ListNode * last = NULL;
    
    while (cin >> value) {
        current = new ListNode(value);
        if (!head) {
            last = head = current;
        } else {
            last->next = current;
            last = current;
        }
    }

    current = head;
    while (current) {
        cout << current->val << endl;
        current = current->next;
    }
    
    Solution * so = new Solution;
    head = so->deleteDuplicates(head);
    
    cout << endl;
    current = head;
    while (current) {
        cout << current->val << endl;
        current = current->next;
    }
    
    return 0;
}
