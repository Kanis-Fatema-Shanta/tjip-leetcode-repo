// TC : O(2N) -> O(N) // SC = O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector <vector <int>> levewise_node;
        queue <TreeNode* > Q;
        Q.push(root);
        while (!Q.empty()) {
            int len = Q.size();
            vector<int> nodes;
            for (int i =0 ; i<len ; i++){
                auto u = Q.front();
                Q.pop();
                nodes.push_back(u -> val);
                if(u -> left) Q.push(u -> left);
                if(u -> right) Q.push(  u -> right);

            }
            levewise_node.push_back(nodes);

        }
        int i = 0;
        for(auto &nodes : levewise_node){
            if(i % 2 == 1){
                reverse(nodes.begin(), nodes.end());
            }
            i++;
        }
        return levewise_node;
        
    }
};