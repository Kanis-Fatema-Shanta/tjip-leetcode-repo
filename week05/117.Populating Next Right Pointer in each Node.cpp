class Solution {
public:
    // TC : O(N) --- N each node
    // MC : O(L) --- Maximum nodes of the level in the binary tree
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int len = Q.size();
            for(int i =0 ; i<len ;i++) {
                auto u = Q.front();
                Q.pop();
                if(i+1 < len) {
                    u -> next = Q.front();

                }
                if( u -> left) Q.push(u -> left);
                if( u -> right) Q.push(u -> right);

            }
        } return root;
        
    }
    

        

};