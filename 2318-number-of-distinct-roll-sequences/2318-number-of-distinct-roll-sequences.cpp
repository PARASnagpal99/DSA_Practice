class Solution {
public:
    int mod = 1e9 + 7 ;
    int dp[10005][7][7] ;
    
    int func(int indx , int prev1 , int prev2 , int n){
        if(indx==n){
            return 1 ;
        }
        
        if(dp[indx][prev1][prev2]!=-1) return dp[indx][prev1][prev2] ;
        int ans = 0 ;
        
        for(int i=1 ; i<=6 ; ++i){
            if(i!=prev1 && i!=prev2 && (prev1==0 or __gcd(i,prev1)==1)){
                ans = (ans + func(indx+1,i,prev1,n))%mod ; 
            }
        }
        
        return dp[indx][prev1][prev2] = ans ;
    }
    
    
       
    
    int distinctSequences(int n) {
       memset(dp,-1,sizeof(dp));
       int ans = func(0,0,0,n) ;
       return ans ; 
        
        
        
    }
};