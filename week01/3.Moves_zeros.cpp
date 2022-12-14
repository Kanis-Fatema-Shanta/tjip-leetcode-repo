class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int count=0;
        while(i<nums.size()){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                i--;
                count++;
            }
                i++;
        }
        while(count!=0){
            nums.push_back(0);
            count--;
        }
    }
};
