class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
          int n = matrix.size() , m = matrix[0].size() ;
          vector<vector<int>>dp(n,vector<int>(m,0));
          
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(i==0 && matrix[i][j]==1) dp[i][j] = 1 ;
                if(j==0 && matrix[i][j]==1) dp[i][j] = 1 ;
            }
        }
        
        
        for(int i=1 ; i<n ; ++i){
            for(int j=1 ; j<m ; ++j){
                if(matrix[i][j]==1){
                    int cnt ;
                    cnt = min(dp[i-1][j] , dp[i-1][j-1]) ;
                    cnt = min(dp[i][j-1] , cnt );
                    dp[i][j] = cnt ;
                    dp[i][j]+=1;
                }
            }
        }
        
        int ans = 0 ;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                ans+= dp[i][j] ;
            }
        }
        
        return ans ;
        
    }
};