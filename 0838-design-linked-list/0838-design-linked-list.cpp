class Node {
public:
    int val;
    Node *next;
    
    Node (int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
    Node* head;
public:
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        Node* ptr = head;
        while(ptr && index>0) {
            index--;
            ptr = ptr->next;
        }
        if(index>0 || ptr==NULL) return -1;
        return ptr->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        if(!head) {
            head = newNode;
            return;
        }
        Node *ptr = head;
        while(ptr->next) ptr = ptr->next;
        if(ptr) ptr->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        Node *newNode = new Node(val);
        if(index==0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        index-=1;
        Node *ptr = head;
        while(ptr && index>0) {
            index--;
            ptr = ptr->next;
        }
        if(index>0 || ptr==NULL) return;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        if(!head) return;
        if(index==0) {
            if(head) head = head->next;
            return;
        }
        Node *ptr = head;
        index--;
        while(ptr->next && index>0) {
            index--;
            ptr = ptr->next;
        }
        if(index>0 || !ptr->next) {
            return;
        }
        ptr->next = ptr->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */