class Solution {
public:
    #define ll long long int
    int mod = 1e9 + 7 ;
    
    ll dp[100005] ;
    
    ll func(int indx , string &s , int k  ){
        ll n = s.length() ;
        
        if(indx == n) return 1 ;
            
        if(dp[indx]!=-1) return dp[indx] ;
        
        ll ans = 0 ;
        
        ll num = 0 ;
        
        for(int i=indx ; i<n ; ++i){
            
            num = (num*10 + (s[i] - '0')) ;
            
            if(num >=1 && num <=k ){
                ans = (ans + func(i+1,s,k))%mod ;
            }else{
                break ;
            }
        }
        
        return dp[indx] = ans%mod ;
    }

    
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        ll ans = func(0,s,k);
        return (int)ans ;
    }
};