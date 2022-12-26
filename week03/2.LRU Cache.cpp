//TC : O(logN)  MC : O(N)
class DoubleLL{
    public:
    int key;
    int val;
    DoubleLL*prev;
    DoubleLL*next;

    DoubleLL(int k,int v){
        this->key=k;
        this->val=v;
        this->prev=NULL;
        this->next=NULL;
    }
};

class LRUCache {
    int size;
    DoubleLL *head;
    DoubleLL *tail;
    unordered_map<int,DoubleLL*>mp;

public:
    // A Constructor for setting size, head and tail pointers. 
    LRUCache(int capacity) {
        this->size=capacity;
        head=new DoubleLL(-1,-1);
        tail=new DoubleLL(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    // TO Get the value of key given
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        else{
            DoubleLL *curr=mp[key];
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            curr->prev=head;
            curr->next=head->next;
            head->next->prev=curr;
            head->next=curr;
            // Returning the value.
            return mp[key]->val;
        }
    }
    
    void eraseFromLL(int key){
       
        DoubleLL *temp=mp[key];

        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        
        temp->prev=NULL;
        temp->next=NULL;
        mp.erase(key);
    }

    // Function to put the value in map and LinkedList.
    void put(int key, int value) {
        
        if(mp.find(key)==mp.end()){
            DoubleLL *curr=new DoubleLL(key,value);
            mp[key]=curr;
            curr->prev=head;
            curr->next=head->next;
            head->next->prev=curr;
            head->next=curr;
        
            if(mp.size()>this->size)
                eraseFromLL(tail->prev->key);
        }
        else{
            eraseFromLL(key);
            DoubleLL *curr=new DoubleLL(key,value);
            mp[key]=curr;
            curr->prev=head;
            curr->next=head->next;

            head->next->prev=curr;
            head->next=curr;
        }
    }
};

/*
Size=2
head<->c{3,3}<->a{1,1}<->tail

Hash={(1,a),(3,c)}


*/


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */