class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n=nums.size();

        // till n-2 bcz at last 3rd position
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i] != nums[i-1]))   // prevention from duplicate no.
            {
                int low = i+1;
                int high = n-1;
                int sum = 0 -nums[i];

                while(low<high)
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);

                        res.push_back(temp);

                        //for skip the same number
                        while(low<high && nums[low] == nums[low+1])
                        {
                            low++;
                        }
                        while(low<high && nums[high] == nums[high-1])
                        {
                            high--;
                        }

                        //iterate forward
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        return res;

    }
};
