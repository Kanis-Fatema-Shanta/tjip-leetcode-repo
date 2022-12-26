//TC : O(N) MC: O(N)
class Solution {
public:
    string subtree(TreeNode* root, unordered_map<string,int> &um, vector<TreeNode*> &ans)
    {
        // this is very important base case
        /* for example

             6                     6
            / \           AND       \
           /   \                     5
          5     4                     \
                                       4
        
        */
        if(root == NULL)
        {
            return "$";
        }
        string s = "";
        
        // concatination of present node + left node + right node.
        s = to_string(root -> val) +"&"
            + subtree(root -> left,um,ans)+"&"
            + subtree(root -> right,um,ans);

        // count the number of subtree.
        um[s]++;

        // is count of subtree == 2 it means it duplicate
        if(um[s] == 2)
        {
            ans.push_back(root);
        } 
        
        return s;   
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // creating the vector for storing final answer.
        vector<TreeNode*> ans;
        // creating unordered map for storing subtree ans it's count
        unordered_map<string, int> um;
        subtree(root, um, ans);
        return ans;
    }
};