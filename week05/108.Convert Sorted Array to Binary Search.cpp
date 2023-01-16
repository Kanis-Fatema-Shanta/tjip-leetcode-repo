/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //  TC : O(N*2) // SC : O(N)
    TreeNode* constructBSTfrom(vector<int>& nums, int L , int R) {
        if( L > R) return NULL;
        int M = L +(R -L) /2;
        TreeNode* root = new TreeNode(nums[M]);
        root -> left = constructBSTfrom(nums, L , M-1);
        root -> right = constructBSTfrom(nums, M+1, R);
        return root;
    }
    TreeNode* sortedArrayToBST( vector <int> & nums) {
        return constructBSTfrom(nums,0, nums.size() -1 );
    }


};