class Solution {
public:
    #define ll long long 
    static const int MOD = 1e9 + 7 ;
    int countTexts(string s) {
        int n = s.length() ;
        vector<ll>dp(n+1);
        dp[0] = 1 ;
        for(int i=0 ; i<n ; ++i){
            dp[i+1] = dp[i]%MOD ;
            if(i>=1 && s[i]==s[i-1]){
                dp[i+1] = (dp[i+1] + dp[i-1])%MOD ;
                if(i>=2 && s[i]==s[i-2]){
                    dp[i+1] = (dp[i+1] + dp[i-2])%MOD ;
                     if(i>=3 && s[i]==s[i-3] && (s[i]=='9' or s[i]=='7')){
                       dp[i+1] = (dp[i+1] + dp[i-3])%MOD ;
                     }
               }
            }
           
        }
        return dp[n] ;
    }
};