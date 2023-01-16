// TC : O(N) --/ N-> each node of the tree // SC : O(N)
class Solution {
public:
    void traverse(TreeNode* root , int curr_depth , int &max_depth){
        if (root == NULL) return;
        max_depth = max(max_depth, curr_depth);
        traverse(root -> left , curr_depth+1 , max_depth);
        traverse(root -> right , curr_depth+1, max_depth);
    }
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        traverse(root , 1, max_depth);
        return max_depth; 
        
        
    }
};