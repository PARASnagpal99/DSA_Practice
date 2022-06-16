class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n,1) ;
        int len = 0 ;
        
        for(int i=0 ; i<n ; ++i){
            for(int prev=0 ; prev < i ; prev++){
                
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i] , 1 + dp[prev]) ; // dp[i] signifies the length of longest increasing subsequence that ends at index i 
                }
            }
            len = max(len , dp[i]) ;
        }
        
        return len ;
    }
};