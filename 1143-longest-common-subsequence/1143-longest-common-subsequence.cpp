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
          if(m==0 or n==0) return 0 ;
          vector<vector<int>>dp(m ,vector<int>(n,0)) ;
          int ans = 0 ;
          ans+=func(text1,text2,m-1,n-1,dp);
          return ans ;
    }
};