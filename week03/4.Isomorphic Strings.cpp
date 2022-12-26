class Solution {
public:
    bool isIsomorphic(string s, string t) {
	//TC= O(n) MC = O(n)
        map<char, char> m;
        int n = s.size();
        map<char,char> :: iterator it;

        for(int i=0; i<n; i++){
            if(m.count(s[i])){

                if(m[s[i]]!= t[i]){
                    return false;
                }
            }
            else{
                m.insert({s[i], t[i]});
            }
        }

        set<int> freq ;
        
        for(it=m.begin(); it!=m.end(); it++){

            freq.insert(it->second);
        }

        if(freq.size()!=m.size()){
            return false;
        }

        return true;
    }
};