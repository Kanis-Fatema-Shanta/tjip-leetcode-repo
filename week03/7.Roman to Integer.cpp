class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman;
        //I             1
        //V             5
        //X             10
        //L             50
        //C             100
        //D             500
        //M             1000
        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;
        int sum=0,i=0;
        
        for(int i=0;i<s.length()-1;i++){
            if(roman[s[i]]>=roman[s[i+1]]){
                sum+=roman[s[i]];
            }
            else{
                sum-=roman[s[i]];
            }
        }
        sum+=roman[s[s.length()-1]];
        return sum;
        
    }
};