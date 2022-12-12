class Solution {
public:
    string minWindow(string s, string t) {
        
        int sl = s.length();
        int tl = t.length();
        
        if(sl < tl) return "";
        
        // store freq of given string t
        int freq[52] = {};
        
        for( char &c : t)
        {
            if(c>='A' && c<='Z')freq[c-'A'+26]++;
            else freq[c-'a']++;
        }
            
        
        int count = 0;
        int rlen = INT_MAX;
        int rindex;

        int first = 0;
        int last = 0;
        int index;
        
        // store sliding window char freq
        int tfreq[52] = {};
        int len;
        
        // slide window from left to right 
        while(last < sl)
        {
            index = (s[last]>='A' && s[last]<='Z') ? s[last]-'A'+26 : s[last]-'a';
            
            // increment current window char freq if exists in given string t
            if(freq[index] > 0)
            {
                if(tfreq[index] < freq[index])count++;
                
                tfreq[index]++;
            }
            
            
            // shrink window from left to right means increment first pointer
            // when valid char count == given string char count
            while(count == tl)
            {
                len = last - first + 1;
                
                // update string length and first index 
                if(rlen > len)
                {
                    rlen =  len;
                    rindex = first;
                }
                
                index = (s[first]>='A' && s[first]<='Z') ? s[first]-'A'+26 : s[first]-'a';
                
                
                // decrement char freq for first char in the previous window as
                // we slide first pointer from left to right
                if(freq[index] > 0)
                {
                    if(tfreq[index] <= freq[index])count--;

                    tfreq[index]--;
                }
                
                first++;
            }
            
            last++;
        }
        
        // return empty string for so result, otherwise return substring from rindex with length rlen
        return rlen == INT_MAX ? "" : s.substr(rindex,rlen);
    }
};