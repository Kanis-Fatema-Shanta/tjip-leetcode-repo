// TC : O(NLogN) // SC: O(N)
class Solution {
public:
    
    vector<pair<int, int>> pairs;
    
    int getHeight(TreeNode *root) {
        if (!root) return -1;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int currHeight = max(leftHeight, rightHeight) + 1;
        this->pairs.push_back({currHeight, root->val});
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->pairs.clear();
        getHeight(root);
        sort(this->pairs.begin(), this->pairs.end());
        int n = this->pairs.size(), height = 0, i = 0;
        vector<vector<int>> solution;
        while (i < n) {
            vector<int> nums;
            while (i < n && this->pairs[i].first == height) {
                nums.push_back(this->pairs[i].second);
                i++;
            }
            solution.push_back(nums);
            height++;
        }
        return solution;
    }
};