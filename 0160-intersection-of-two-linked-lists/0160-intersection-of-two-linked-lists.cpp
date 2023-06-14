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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // int l1 = 0, l2 = 0;
        // ListNode *ptr1 = headA, *ptr2 = headB;
        // while(ptr1) {
        //     ++l1;
        //     ptr1 = ptr1->next;
        // }
        // while(ptr2) {
        //     ++l2;
        //     ptr2 = ptr2->next;
        // }
        // ptr1 = headA, ptr2 = headB;
        // if(l1>l2) {
        //     l1 = (l2-l1);
        //     while(l1<0) {
        //         ++l1;
        //         ptr1 = ptr1->next;
        //     }
        // }
        // else if(l2>l1) {
        //     l2 = (l1-l2);
        //     while(l2<0) {
        //         ++l2;
        //         ptr2 = ptr2->next;
        //     }
        // }
        // while(ptr1 && ptr2) {
        //     if(ptr1==ptr2) return ptr1;
        //     ptr1 = ptr1->next;
        //     ptr2 = ptr2->next;
        // }
        // return NULL;

        ListNode* tail = headA, *slow = headB, *fast = headB;
        while(tail->next) {
            tail = tail->next;
        }
        tail->next = headA;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) {
                slow = headB;
                while(slow!=fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                tail->next = NULL;
                return slow;
            }
        }
        tail->next = NULL;
        return NULL;
    }
};