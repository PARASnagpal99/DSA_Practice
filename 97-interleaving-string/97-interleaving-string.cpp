class Solution {
public:
    int dp[105][105][205] ;
    bool func(int i , int j , int k , string &s1 , string &s2 , string &s3 ){
        
        // base case 
        if(i>=s1.size() && j>=s2.size() && k >= s3.size()) return true ;
        if(k >= s3.size()) return false ;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k] ;
        
        bool choice1 = ((s1[i]==s3[k]) && func(i+1,j,k+1,s1,s2,s3)) ;
        bool choice2 = ((s2[j]==s3[k]) && func(i,j+1,k+1,s1,s2,s3)) ;
        
        
        return dp[i][j][k] = choice1 | choice2 ;
        
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int i = s1.length() , j = s2.length() , k = s3.length() ;
        memset(dp,-1,sizeof(dp)) ;
        return func(0,0,0,s1,s2,s3) ;
    }
};