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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode *cur, *prev = NULL, *nxt, *ptr = head, *prevStore = NULL;
        int pos = 1;
        while(ptr) {
            if(pos == left) break;
            prev = ptr;
            ptr = ptr->next;
            pos++;
        }
        prevStore = prev;
        cur = ptr;
        if(ptr) nxt = ptr->next;
        while(cur) {
            cur->next = prev;
            prev = cur;
            cur = nxt;
            if(cur!=NULL) nxt = cur->next;
            if(pos==right) break;
            pos++;
        }
        // if(prev->val!=right) {
        //     prev = cur;
        //     cur = NULL;
        // }
        if(!prevStore) {
            prevStore = head;
            head = prev;
            prevStore->next = cur;
        }
        else {
            ptr = prevStore->next;
            ptr->next = cur;
            prevStore->next = prev;
        }
        return head;
    }
};