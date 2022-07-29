class Solution {
public:
    
    int func(int indx , string &s , vector<int> &dp){
        int n = s.length() ;
        
        if(indx >= n) return 1 ;
        
        if(s[indx] == '0') return 0 ;
        
        if(dp[indx]!=-1) return dp[indx] ;
        
        int choice1 = func(indx+1,s,dp);
        int choice2 = 0 ;
        if(indx <= n-2 && (s[indx] == '1' or (s[indx] == '2' && s[indx+1] <= '6'))){
            choice2 += func(indx+2,s,dp) ;
        }
        
        int ans = choice1 + choice2 ;
        return dp[indx] = ans ;
    }
    
    
    int numDecodings(string s) {
         int n = s.length() ;
         vector<int> dp(n+1,-1);
         int ans = func(0,s,dp);
         return ans ;
    }
};