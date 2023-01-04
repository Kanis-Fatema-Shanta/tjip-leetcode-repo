class MyLinkedList {
public:
    // TC : N(logN)
    // MC : O(N)

    class Node{
    public:
        int value;
        Node* next;
        Node(int _value , Node* _next) {
            value = _value;
            next = _next;
        }   
    };
    const static int DummyValue = INT_MIN;
    Node* head = NULL;
    int len;
    // [DummyValue , NULL] -> (1, addr(2), ->(2,addr(3) -> (3, NULL))
    MyLinkedList() {
          len = 0;
          head = new Node(DummyValue , NULL);

    }
    int get(int index) {
        if(index < 0 || index >= len) return -1;
        auto CurrentNode = head -> next;
        while(index--) {
            CurrentNode = CurrentNode -> next;
        }
        return CurrentNode -> value;
        
    }
    //defined
    void addAtHead(int val) {
        addAtIndex(0, val);

    }
    
    void addAtTail(int val) {
        addAtIndex(len , val);
        
    }
    
    void addAtIndex(int index, int val) {
        if( index < 0 || index > len ) return;
        auto CurrentNode = head;
        while(index--) {
            CurrentNode = CurrentNode -> next;
        }
        auto nxt = CurrentNode -> next;
        CurrentNode -> next =  new Node(val , NULL);
        CurrentNode -> next -> next = nxt;
        len++;

        
    }
    
    void deleteAtIndex(int index) {
        if( index < 0 || index >= len ) return;
        auto CurrentNode = head;
        while(index--) {
            CurrentNode = CurrentNode -> next;
        }
        auto nxt = CurrentNode -> next;
        CurrentNode -> next = CurrentNode -> next -> next;
        delete(nxt);
        len--;
        
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