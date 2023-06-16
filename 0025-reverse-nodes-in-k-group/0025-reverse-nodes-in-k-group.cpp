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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len = 0, flg = 0, cnt = 0;
        ListNode* ptr = head;
        while(ptr) {
            len++;
            ptr = ptr->next;
        }
        len /= k;
        ptr = head;
        ListNode *cur = head, *prev = NULL, *nxt = head, *ptr1 = head;
        while(1) {
            if(flg==k) {
                cnt++;
                if(ptr1==head) head = prev;
                if(cnt>1) {
                    cnt--;
                    ptr->next = prev;
                    ptr = ptr1;
                }
                ptr1 = cur;
                prev = NULL;
                flg = 0;
                len--;
                if(len<=0) break;
            }
            flg++;
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        ptr->next = ptr1;
        return head;
    }
};