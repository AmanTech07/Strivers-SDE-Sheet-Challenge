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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0, flg = 0;
        ListNode *ptr=head, *prev=NULL;
        while(ptr) {
            cnt++;
            if(cnt>n && flg==0) {
                prev = head;
                flg = 1;
            }
            else if(flg) {
                prev = prev->next;
            }
            ptr = ptr->next;
        }
        if(prev) prev->next = prev->next->next;
        if(n==cnt) head = head->next;
        return head;

        // ------------------------TC: O(m)-----------------------
        // ------------------------SC: O(1)-----------------------
    }
};