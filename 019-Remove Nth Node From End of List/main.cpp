/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            int a = 0, b = 0;
            ListNode *A = head, *B = head;
            for (; B->next != NULL; B = B->next) {
                if (b - a == n) {++a; A = A->next;}
                ++b;
            }
            if (b < n - 1) return NULL;
            if (b == n - 1 && a == 0) head = head->next;
            else {
                B = A->next;
                A->next = B->next;
            }
            return head;
        }
};
