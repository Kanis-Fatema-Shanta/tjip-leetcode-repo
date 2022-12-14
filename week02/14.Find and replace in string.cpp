class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans = "";
        unordered_map<int,pair<string,string>> m;
        for(int i=0;i<indices.size();i++){
            int ind = indices[i];
            int len = sources[i].length();
            if(s.substr(ind,len) == sources[i]){
                m[ind] = {sources[i] , targets[i]};
            }
        }
        int i=0;
        while(i < s.length()){
            if(m.find(i) != m.end()){
                ans += m[i].second;
                i += m[i].first.length();
            }else{
                ans += s[i++];
            }
        }
        return ans;
    }

    // Case 1:

    // s = "abcd", indices = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
    // Output: "eeebffff"

    // Case 2:
    // s = "abcd", indices = [0, 2], sources = ["ab","ec"], targets = ["eee","ffff"]
    // Output: "eeecd"
    
};