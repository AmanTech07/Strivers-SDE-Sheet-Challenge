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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ptr1 = l1, *ptr2 = l2, *head = NULL, *ptr = NULL;
        while(ptr1 && ptr2) {
            int sum = ptr1->val + ptr2->val + carry;
            int num = sum%10;
            sum /= 10;
            carry = sum;
            ListNode* node = new ListNode(num);
            if(ptr==NULL) {
                head = ptr = node;
            }
            else{
                ptr->next = node;
                ptr = node;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while(ptr1) {
            int sum = ptr1->val + carry;
            int num = sum%10;
            sum /= 10;
            carry = sum;
            ListNode* node = new ListNode(num);
            if(ptr==NULL) {
                head = ptr = node;
            }
            else {
                ptr->next = node;
                ptr = node;
            }
            ptr1 = ptr1->next;
        }
        while(ptr2) {
            int sum = ptr2->val + carry;
            int num = sum%10;
            sum /= 10;
            carry = sum;
            ListNode* node = new ListNode(num);
            if(ptr==NULL) {
                head = ptr = node;
            }
            else {
                ptr->next = node;
                ptr = node;
            }
            ptr2 = ptr2->next;
        }
        if(carry>0) {
            while(carry) {
                int num = carry%10;
                ListNode* node = new ListNode(num);
                ptr->next = node;
                ptr = node;
                carry /= 10;
            }
        }
        return head;
    }
};