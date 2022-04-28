class Solution {
public:
    int dp[105][105] ;
    int func(int m , int n){
        if(dp[m][n]!=-1) return dp[m][n] ;
        if(m<0 or n<0){
            return 0 ;
        }else if(m==0 or n==0){
            return 1 ;
        }else{
            return dp[m][n] = func(m-1,n) + func(m,n-1);
        }
    }
    
    int uniquePaths(int m, int n) {
            memset(dp,-1,sizeof(dp));
            return func(m-1,n-1);    
    }
};