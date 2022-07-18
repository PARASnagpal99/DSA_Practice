class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size() ;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ;
        
        
        for(int i=1 ; i<=n ; ++i){
            for(int j=1 ; j<=m ; ++j){
                dp[i][j] = dp[i][j-1] + matrix[i-1][j-1] ;
            }
        }
        
        
        for(int j=1 ; j<=m ; ++j){
            for(int i=1 ; i<=n ; ++i){
                dp[i][j] += dp[i-1][j] ;
            }
        }
        
        
        int cnt = 0 ;
        
        for(int i=1 ; i<=n ; ++i){
            for(int j=1 ; j<=m ; ++j){
                
                for(int k=i ; k<=n ; ++k){
                    for(int l=j ; l<=m ; ++l){
                        
                        // int bottom_left = min(j,l);
                        // int top_up = min(i,k) ;
                        // int bottom_right = max(j,l);
                        // int top_down = max(i,k) ;
                        
                        int sum = dp[i-1][j-1] + dp[k][l] - dp[k][j-1] - dp[i-1][l] ;
                            
                        if(sum == target) cnt++;
                        
                    }
                }
            }
        }
        
        
        
        return cnt ;
        
        
        
        
        
        
        
        
    }
};