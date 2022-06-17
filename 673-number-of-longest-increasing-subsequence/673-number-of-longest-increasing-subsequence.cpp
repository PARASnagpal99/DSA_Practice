class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n,1);
        vector<int> count(n,1) ;
        int maxlen = 0 ;
        for(int i=0 ; i<n ; ++i){
            for(int prev = 0 ; prev < i ; ++prev){
                
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev] ;
                    count[i] = count[prev] ;
                }else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]){
                    count[i]+=count[prev] ;
                }
            }
            maxlen = max(maxlen,dp[i]);
        }
        
        int ans = 0 ;
        for(int i=0 ; i<n ; ++i){
            if(dp[i]==maxlen) ans+=count[i] ;
        }
        return ans ;
        
    }
};