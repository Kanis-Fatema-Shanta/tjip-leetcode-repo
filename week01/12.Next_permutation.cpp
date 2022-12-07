class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int k = -1;

        for(int i=nums.size()-2;i>=0;i--){

           if(nums[i]<nums[i+1]){
               k=i;
               break;

           }
        }

        if(k==-1)
        reverse(nums.begin(),nums.end());

        else{

            int j;
            for(j=nums.size()-1;j>=0;j--){

                if(nums[j]>nums[k])
                break;

            }
            swap(nums[k],nums[j]);
            reverse(nums.begin()+k+1,nums.end());

        }        

    }
};