// TC: O(N)
// MC : O(N)

class Solution {
public:
   
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0, n = points.size();
         unordered_map<double,int> um;
        for(int i = 0 ; i < n; i ++){
            //clear the map
            um.clear();
            
             int x1 = points[i][0];
             int y1 = points[i][1];
             int lmax = 0, same = 1;
            
            for(int j = i+1; j  < n; j ++){
               int x2 = points[j][0];
               int y2 = points[j][1];
                if(x1 ==  x2 && y1 == y2){
                    same++;
                }
                else if(x1 != x2){
                    double constant = (double)(y1 - y2) / (double)(x1 - x2);
                    um[constant]++;
                }else{
                    um[INT_MAX]++;
                }
                
            }
            
            for(auto it : um){
            lmax = max(lmax,it.second);
            }
            
            ans = max(lmax+same,ans);
        }
        
        
        
        return ans;
    }
};