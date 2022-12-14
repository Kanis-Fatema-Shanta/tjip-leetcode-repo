#include <bits/stdc++.h>
//#include<vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end()&&i!=map[target-nums[i]])
                return {i,map[target-nums[i]]};
        }
        return {0};
    }


};
