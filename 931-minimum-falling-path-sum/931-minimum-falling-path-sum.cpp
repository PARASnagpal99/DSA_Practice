class Solution {
public:
    int dp[105][105] ;
    int func(int i , int j , vector<vector<int>>& matrix ){
        int m = matrix[0].size() ;
        if(j<0 or j>=m) return 1000000 ;
        if(i==0) return matrix[i][j] ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int ans1 = matrix[i][j] + func(i-1,j,matrix) ;
        int ans2 = matrix[i][j] + func(i-1,j-1,matrix);
        int ans3 = matrix[i][j] + func(i-1,j+1,matrix);
        return dp[i][j] = min(min(ans1,ans2),ans3);
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
            memset(dp,-1,sizeof(dp));
            int m = matrix.size() , n = matrix[0].size() ;
            int ans = 1000000000;
            for(int i=0 ; i<n ; ++i){
                ans = min(ans,func(m-1,i,matrix));
            }
        return ans ;
    }
};