/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ptr = head, *head1 = NULL, *cur = NULL;
        int x = 0;
        while(ptr) {
            Node *tmp = new Node(ptr->val);
            if(!head1) {
                head1 = tmp;
            }
            else {
                cur->next = tmp;
            }
            cur = tmp;
            ptr->val = x++;
            ptr = ptr->next;
        }
        ptr = head;
        cur = head1;
        while(ptr) {
            if(ptr->random) {
                int num = ptr->random->val, len = 0;
                Node *tmp = head1;
                while(tmp) {
                    if(len==num) {
                        cur->random = tmp;
                    }
                    len++;
                    tmp = tmp->next;
                }
            }
            ptr = ptr->next;
            cur = cur->next;
        }
        return head1;
    }
};