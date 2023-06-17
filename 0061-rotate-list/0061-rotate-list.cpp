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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        int len = 0;
        while(slow) {
            len++;
            slow = slow->next;
        }
        if(k>len) k %= len;
        if(k==0) return head;
        slow = head;
        while(fast->next) {
            k--;
            fast = fast->next;
            if(k<0) slow = slow->next;
        }
        if(k<=0) {
            fast->next = head;
            head = slow->next;
            slow->next = NULL;
        }
        return head;
    }
};