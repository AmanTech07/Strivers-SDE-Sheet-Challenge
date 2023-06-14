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
    ListNode* reverse(ListNode* head, ListNode* ptr, ListNode* prev) {
        if(!ptr->next) {
            head = ptr;
            ptr->next = prev;
            return head;
        }
        head = reverse(head, ptr->next, ptr);
        ptr->next = prev;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        // -------------------Iterative-----------------------

        // ListNode* ptr = head, *prev = NULL, *tmp;
        // while(ptr) {
        //     tmp = ptr->next;
        //     ptr->next = prev;
        //     prev = ptr;
        //     ptr = tmp;
        // }
        // return prev;

        // ----------------------Recursive-----------------------

        ListNode* ptr = head, *prev = NULL;
        if(head) head = reverse(head, ptr, prev);
        return head;
    }
};