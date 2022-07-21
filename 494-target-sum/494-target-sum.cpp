class Solution {
public:
    int dp[25] ;
    int func(int indx , int target , vector<int> &nums , int sum){
        
        if(indx < 0 && sum == target) return 1 ;
        
        if(indx < 0 ) return 0 ;
        
        if(dp[indx]!=-1) return dp[indx] ;
        
        int ans = 0 ;
        
        int choice1 = func(indx-1 , target , nums , sum + nums[indx]) ;
        
        int choice2 = func(indx-1, target , nums , sum - nums[indx] ) ;
        
        ans += (choice1 + choice2) ;
        
        return ans ;
    }
    
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        memset(dp,-1,sizeof(dp));
        return func(n-1,target,nums,0) ;
    }
};