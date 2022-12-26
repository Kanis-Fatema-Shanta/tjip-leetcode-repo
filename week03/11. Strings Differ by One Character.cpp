// TC : O(N)
// MC : O(N)
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_map<string, bool> memo;
        for (int i = 0; i < dict.size(); i++) {
            string s = dict[i];
            for(int j = 0; j < s.length(); j++) {
                char ch = s[j];
                s[j] = ':';
                if (memo[s]) return true;
                memo[s] = true;
                s[j] = ch;
            }
        }
        
        return false;
    }
};