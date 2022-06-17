class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n,vector<int>(3,0));
        
        dp[0][(nums[0])%3] = nums[0] ;
        
        for(int i=1 ; i<n ; ++i){
            int x = dp[i-1][0] + nums[i] ;
            int y = dp[i-1][1] + nums[i] ;
            int z = dp[i-1][2] + nums[i] ;
            
            dp[i] = dp[i-1] ;
            
            dp[i][x%3] = max(x,dp[i][x%3]);
            dp[i][y%3] = max(y,dp[i][y%3]);
            dp[i][z%3] = max(z,dp[i][z%3]);
        }
        
        return dp[n-1][0] ;
        
    }
};