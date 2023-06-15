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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head, *mid;
        while(fast) {
            slow = slow->next;
            mid = fast;
            fast = fast->next;
            if(fast) {
                mid = fast;
                fast = fast->next;
            }
        }
        ListNode *prev=NULL, *cur=slow, *next;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur; 
            cur = next;
        }
        ListNode *a = prev, *b = head;
        while(a) {
            if(a->val!=b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};