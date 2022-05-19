class Solution {
public:
    int dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
          int n = grid.size() , m = grid[0].size() ;
          if(dp[i][j]){
              return dp[i][j] ;
          }
        vector<pair<int,int>>drctns = {{0,1},{-1,0},{1,0},{0,-1}} ;
        int res = 1 ;
        for(int a=0 ; a<4 ; ++a){
            int x = i + drctns[a].first ;
            int y = j + drctns[a].second ;
            if(x<0 or y<0 or x>=n or y>=m) continue ;
            if(grid[x][y]<=grid[i][j]) continue ;
            res = max(res,1+dfs(x,y,grid,dp));
        }
        return dp[i][j] = res ;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ;
        if(n==0) return 0 ;
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans = 0 ;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                ans = max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans ;
    }
};