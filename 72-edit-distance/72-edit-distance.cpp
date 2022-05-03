class Solution {
public:
    int dp[505][505] ;
    int func(string &word1, string &word2 , int i , int j){
        if(i<0) return (1 + j);
        if(j<0) return (1 + i);
        if(dp[i][j]!=-1) return dp[i][j] ;
        if(word1[i]==word2[j]) return dp[i][j] = func(word1,word2,i-1,j-1);
        int insert = 1 + func(word1,word2 ,i,j-1);
        int replace = 1 + func(word1,word2,i-1,j-1);
        int delet = 1 + func(word1,word2,i-1,j);
        return dp[i][j] = min(insert,min(delet,replace));
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size() , n = word2.size() ;
        memset(dp,-1,sizeof(dp));
        return func(word1,word2,m-1,n-1);
    }
};