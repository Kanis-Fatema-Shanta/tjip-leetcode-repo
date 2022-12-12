class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};

// Approach 2

class Solution {
public:
    static const int BASE = 397;
    static const long long MOD = 100000007;

    long long getHash(string &s)
    {
        long long H =1;
        for(auto c : s)
        {
            H  *= (BASE + c);
            if( H >= MOD)
                H %= MOD;
        }
        return H;
    }
    bool isAnagram(string s, string t) {
       
        return getHash(s) == getHash(t);
    }
};