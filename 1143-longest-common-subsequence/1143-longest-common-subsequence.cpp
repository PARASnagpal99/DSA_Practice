class Solution {
public:
    int func(string &s1 , string &s2 , int i , int j ,  vector<vector<int>>&dp){
        if(i<0 or j<0) return 0 ;
        if(dp[i][j]) return dp[i][j] ;
        int ans = 0 ;
        ans = max(ans,(s1[i]==s2[j]) + func(s1,s2,i-1,j-1,dp)) ;
        ans = max(ans,max(func(s1,s2,i-1,j,dp),func(s1,s2,i,j-1,dp))) ;
        return dp[i][j] = ans  ;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
          int m = text1.length() , n =  text2.length() ;
          vector<vector<int>>dp(m+1,vector<int>(n+1,0));
          for(int i=0 ; i<=m ; ++i) dp[i][0] = 0 ;
          for(int j=0 ; j<=n ; ++j) dp[0][j] = 0 ;
        
          for(int i=1 ; i<=m ; ++i){
              for(int j=1 ; j<=n ; ++j){
                  if(text1[i-1]==text2[j-1]){
                      dp[i][j] = 1 + dp[i-1][j-1] ;
                  }else{
                      dp[i][j] = max(dp[i][j-1],dp[i-1][j]) ;
                  }
              }
          }
          return dp[m][n] ;
    }
};