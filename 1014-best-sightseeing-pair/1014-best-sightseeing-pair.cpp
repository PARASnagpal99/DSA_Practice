class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n  = values.size() ;
        int dp = values[0] + 0 ;
        int res = 0 ;
        
        for(int j=1 ; j<n ; ++j){
            int curr = values[j] - j ;
            res = max(curr + dp , res) ;
            dp = max(dp , values[j] + j) ;
        }
        
        return res ;
        
    }
};