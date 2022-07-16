class Solution {
public:
    /*
    
    196 
    5*3 = 15 
    196 - 15 = 181 
    
    */
    const int mod = 1e9 + 7 ;
    int dp[5005][7][20] ;
    
    int func(int indx , int last , int last_count , vector<int> &nums){
        if(indx == 0) return 1 ;
        
        if(dp[indx][last][last_count]!=-1) return dp[indx][last][last_count] ;
        
        int ans = 0 ;
        
        for(int i=1 ; i<=6 ; ++i){
            if(i != last){
                ans = (ans + func(indx-1, i , nums[i-1] - 1 , nums))%mod ;
            }else if(i == last && last_count > 0){
                ans = (ans + func(indx-1, last , last_count - 1 , nums))%mod ;
            }
        }
        
        return dp[indx][last][last_count] = ans%mod ;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        int ans = func(n,0,0,rollMax) ;
        return ans ;
    }
};