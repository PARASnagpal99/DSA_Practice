class Solution {
public:
    int func(int indx , vector<int>&nums , vector<int> &dp ){
        int n = nums.size() ;
        if(indx == n) return 0 ;
        if(indx > n) return 1e7 ;
        if(dp[indx]!=-1) return dp[indx] ;
        
        int cost = 0 ;
        
        int step1 = nums[indx] + func(indx+1,nums,dp) ;
        
        int step2 = nums[indx] + func(indx+2,nums,dp) ;
        
        cost = min(step1,step2) ;
        
        return dp[indx] = cost ;
        
    }
    
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int>dp1(n+1,-1) ;
        int step0 = func(0,cost,dp1) ;
        vector<int>dp2(n+1,-1) ;
        int step1 = func(1,cost,dp2) ;
        return min(step0,step1) ;
    }
};