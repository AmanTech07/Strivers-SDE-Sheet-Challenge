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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head, *ptr1=list1, *ptr2=list2, *ptr;
        if(!list1) return list2;
        else if(!list2) return list1;
        if(ptr1->val<=ptr2->val) {
            head = ptr = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            head = ptr = ptr2;
            if(ptr2) ptr2 = ptr2->next;
        }
        while(ptr1 && ptr2) {
            if(ptr1->val<=ptr2->val) {
                ptr->next = ptr1;
                ptr = ptr->next;
                ptr1 = ptr1->next;
            }
            else {
                ptr->next = ptr2;
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
        }
        while(ptr1) {
            ptr->next = ptr1;
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }
        while(ptr2) {
            ptr->next = ptr2;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        if(ptr) ptr->next = NULL;
        return head;
    }
};