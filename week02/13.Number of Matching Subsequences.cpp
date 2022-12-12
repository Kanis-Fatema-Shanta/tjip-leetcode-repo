class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n=words.size();
        int m=s.length();
        int count=0;
        map<string,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        for(auto it:mp)
        {
            string str=it.first;
            int l=str.length();
            int j=0,k=0;
            while(j<l && k<m)
            {
               if(str[j]==s[k])
               {
                   k++;
                   j++;
               }
                else k++;
            }
            if(j==l)
                count+=it.second;
        }
        return count;
    }
};