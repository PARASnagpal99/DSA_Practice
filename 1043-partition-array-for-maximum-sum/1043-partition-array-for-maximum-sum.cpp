class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> dp(n+1,0);
        dp[n] = 0 ; // base case ;
     
        
        for(int i=n-1 ; i>=0 ; i--){
            
            int len = 0 , max_val = INT_MIN ;
            int sum = 0 , ans = INT_MIN ;
            
            for(int j=i ; j<min(n,i+k) ; j++){ 
                len++;
                max_val = max(max_val,nums[j]);    
                sum = max_val * len + dp[j+1] ;
                ans = max(ans,sum) ;
            }
            
            dp[i] = ans ;
        }
        
        return dp[0] ;
        
        
    }
};