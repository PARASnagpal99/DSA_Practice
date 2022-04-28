class Solution {
public:
//     int dp[105][105] ;
//     int func(int m , int n , vector<vector<int>>& grid){
//         if(m>=0 && n>=0 && grid[m][n]==1) return 0 ;
//         if(m==0 && n==0)return 1 ;
//         if((m<0 or n<0))  return 0 ;
//         if(dp[m][n]!=-1) return dp[m][n] ;
//         return dp[m][n] = func(m-1,n,grid) + func(m,n-1,grid) ;  
        
//     }
    int func2(vector<vector<int>>& grid ,  vector<vector<int>>& dp){
          int m = grid.size() , n = grid[0].size() ;
          for(int i=0 ; i<m ; ++i){
              for(int j=0 ; j<n ; ++j){
                  if(i>=0 && j>=0 && grid[i][j]==1){
                      dp[i][j] = 0 ;
                      continue ;
                  }
                  if(i==0 && j==0){
                      dp[i][j] = 1 ;
                      continue ;
                  }
                  int left = 0 ;
                  int up = 0 ;
                  if(i>0)left = dp[i-1][j];
                  
                  if(j>0)up =dp[i][j-1] ;
                  
                  dp[i][j] = up + left ;
                  
              }
          }    
        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size() ;
       // memset(dp,-1,sizeof(dp));
        vector<vector<int>>dp(m,vector<int>(n,-1)) ;
        
        return func2(obstacleGrid,dp) ;
    }
};