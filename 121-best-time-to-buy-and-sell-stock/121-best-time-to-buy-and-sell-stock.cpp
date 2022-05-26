class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mnm = INT_MAX , ans = INT_MIN ;
       for(auto &it : prices) {
           if(it < mnm){
               mnm = it ;
           }
           ans = max(ans,it-mnm) ;
       }
      return ans ; 
    }
};