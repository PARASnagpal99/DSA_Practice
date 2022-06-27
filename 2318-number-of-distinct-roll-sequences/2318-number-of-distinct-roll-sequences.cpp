class Solution {
public:
    int mod = 1e9 + 7 ;
    int dp[10005][7][7] = {} ;
    
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
          
        for(int prev1 = 0 ; prev1 <= 6 ; ++prev1){
            for(int prev2 = 0 ; prev2 <= 6 ; ++prev2){
                dp[n][prev1][prev2] = 1 ;
            }
        }
        
        for(int ind = n-1;ind >= 0;ind--){ 
			for(int prev1 = 0;prev1 < 7;prev1++){
				for(int prev2 = 0;prev2 < 7 ;prev2++){
					int ans = 0;
					for(int i = 1;i <= 6;i++)
						if(prev1 != i && prev2 != i && (prev1 == 0 || __gcd(prev1,i) == 1))
							ans = (ans + dp[ind+1][i][prev1])%mod;

					dp[ind][prev1][prev2] = ans;
				}
			}
		}
		return dp[0][0][0];
        
        
        
        
        
    }
};