class Solution {
public:
    int dp[105][105] ;
    int func(int m , int n , vector<vector<int>>& grid){
        if(m>=0 && n>=0 && grid[m][n]==1) return 0 ;
        if(m==0 && n==0)return 1 ;
        if((m<0 or n<0))  return 0 ;
        if(dp[m][n]!=-1) return dp[m][n] ;
        return dp[m][n] = func(m-1,n,grid) + func(m,n-1,grid) ;  
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size() ;
        memset(dp,-1,sizeof(dp));
        return func(m-1,n-1,obstacleGrid) ;
    }
};