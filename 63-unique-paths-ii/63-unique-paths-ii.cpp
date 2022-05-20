class Solution {
public:
   int func(vector<vector<int>>& grid ,  vector<vector<int>>& dp){
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
    
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size() , n = Grid[0].size() ;
        vector<vector<int>>dp(m,vector<int>(n,0));
        return func(Grid,dp);
    }
};