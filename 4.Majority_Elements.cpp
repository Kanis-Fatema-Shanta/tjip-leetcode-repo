class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int temp = 1;


        for( int i =1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                temp++;
                 if(temp > (nums.size())/2) {
            return nums[i];
               }

            }
        }

        return nums[0];
    }
};
