class Solution {
public:
    int func(int i , int j, vector<vector<int>>& dp){
        if(i<0 or j<0){
            return 0 ;
        }
        else if(i==0 && j==0) return 1 ;
        else if(dp[i][j]) return dp[i][j] ;
        else return dp[i][j]= (func(i-1,j,dp)+ func(i,j-1,dp)) ;
    }
    
    int uniquePaths(int m, int n) {
            vector<vector<int>>dp(m,vector<int>(n,0));
            return func(m-1,n-1,dp);
    }
};