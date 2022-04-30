class Solution {
public:
    int dp[205][205] ;
    int func(int i , int j , vector<vector<int>>&grid){
        int n = grid.size();
        if(i==n-1) return grid[i][j] ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int ans1 = grid[i][j] + func(i+1,j,grid) ;
        int ans2 = grid[i][j] + func(i+1,j+1,grid);
        return dp[i][j] = min(ans1,ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return func(0,0,triangle);
    }
};