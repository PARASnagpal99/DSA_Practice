class Solution {
public:
    bool canCross(vector<int>& stones) {
       int n = stones.size() ;
        
       unordered_map<int,unordered_set<int>>mp ;
        
       mp[stones[0] + 1] = {1} ; 
       
       for(int i=1 ; i<n ; ++i){
           
           int pos = stones[i] ;
           
           for(auto it : mp[pos]){
               mp[pos+it].insert(it) ;
               mp[pos+it+1].insert(it+1) ;
               mp[pos+it-1].insert(it-1) ;
           }
           
       } 
       
       return (mp[stones[n-1]].size() > 0) ; 
        
        
    }
};