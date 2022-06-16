class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size() ;
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n,1);
        int len = 1 ;
        for(int i=0 ; i<n ; ++i){
            for(int prev = 0 ; prev < i ; prev++){
                if(pairs[prev][1] < pairs[i][0]){
                  dp[i] = max(dp[i], 1 + dp[prev]);  
                }
            }
            len = max(len,dp[i]);
        }
        
        return len ;
    }
};