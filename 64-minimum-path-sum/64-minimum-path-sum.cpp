class Solution {
public:
    int dp[205][205];
    int func(int i , int j ,vector<vector<int>>&grid){
        if(i==0 && j==0) return grid[0][0] ;
        if(i<0 or j<0) return 1000000007;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int up = grid[i][j] + func(i,j-1,grid);
        int left = grid[i][j] + func(i-1,j,grid);
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
          int m = grid.size() , n = grid[0].size();
          memset(dp,-1,sizeof(dp));
          return func(m-1,n-1,grid);
    }
};