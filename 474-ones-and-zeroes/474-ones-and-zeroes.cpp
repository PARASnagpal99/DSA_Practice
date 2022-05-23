class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size() ;
        int dp[sz+1][m+1][n+1] ;
        int ones , zeroes ;
        for(int i=0 ; i<=sz ; ++i){
            if(i>0){
                ones = count(strs[i-1].begin(),strs[i-1].end(),'1') ;
                zeroes = strs[i-1].size() - ones ;
            }
            for(int j=0 ; j<=m ; ++j){
                for(int k=0 ; k<=n ; ++k){
                    if(i==0)
                        dp[i][j][k] = 0 ;
                    else if(j>=zeroes && k>=ones){
                        dp[i][j][k] = max( dp[i-1][j][k] , 1 + dp[i-1][j-zeroes][k-ones] ) ;
                    }else{
                        dp[i][j][k] = dp[i-1][j][k] ;
                    }
                }
            }
        }
        
        return dp[sz][m][n] ;
    }
};