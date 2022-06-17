class Solution {
public:
    
    int func(int i , vector<int> &nums , int state , vector<vector<int>> &dp){
          if(i == nums.size()){
              if(state == 0){
                  return 0 ;
              }
              return -10000 ;
          }    
        if(dp[i][state]!=-1) return dp[i][state] ;
        int take = nums[i] + func(i+1 , nums , (state+nums[i])%3 , dp) ;
        int notTake = func(i+1,nums,state, dp );
        return dp[i][state] = max(take,notTake);
    }
    
    
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        int ans = func(0,nums,0,dp);
        return ans ;
        
    }
};