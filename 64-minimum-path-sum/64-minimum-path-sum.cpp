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
    int n = grid.size() , m = grid[0].size() ;
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
     }
       return dp[n-1][m-1];
    }
};