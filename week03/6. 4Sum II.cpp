//TC : O(n) MC : O(n)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> um;
        for(auto &i: nums1)
        {
            for(auto &j:nums2) um[i+j]++;
        }
        int res{0};
        for(auto &i: nums3)
        {
            for(auto &j: nums4)
            {
                auto it=um.find(-(i+j));
                res+=(it!=um.end())?(it->second):(0);
            }
        }
        return res;
    }
};