class Solution {
public:
    int findlongestSubstringWithUniqueChar(string &s , int k ,int uniqueCharThreshold) {
        /* Input: s = "aaabb", k = 3
            Output: 3
            Input: s = "ababbc", k = 2
            Output: 5 

            // a[abbccc} , k =2;
               UC = and CFK = ?

            */

        int L = 0, R = 0, max_len = 0; 
        int unqCharInWindow = 0 ; //number of unique character
        int cntCharofFreqK = 0; // number of character which frequency at least K
        vector <int > freq(256,0);

        while(R < s.size()){
            freq [s[R]]++;
            unqCharInWindow += (freq[s[R]] == 1); // if(freq[s[R]] == 1) then unqCharInwindow ++ ; 
            cntCharofFreqK  += (freq[s[R]] == k); // freq[S[R]] == k then cntCharofFreq ++;
            R++;

            while( unqCharInWindow > uniqueCharThreshold ){
                freq[s[L]]--;
                unqCharInWindow -= (freq[s[L]] == 0); // if(freq[s[R]] == 0) then unqCharInwindow-- ; 
                cntCharofFreqK  -= (freq[s[L]] == k-1); //
                L++;

            }

            if (unqCharInWindow == cntCharofFreqK){  // aabbccc k=2 uc=3 cfk =3
                max_len = max(max_len , R - L);
            }

        }
        return max_len; 
   }
   int longestSubstring(string s , int k)
   {
       int max_len = 0;
       for( int uniqueChar =1 ; uniqueChar <=26 ; uniqueChar++)
       {
           max_len = max(max_len , findlongestSubstringWithUniqueChar(s,k,uniqueChar) );
       }
       return max_len;
   }

};