class Solution {
public:
    int solve(int indx , vector<int>& arr , vector<int>& dp ){
        if(indx==0) return arr[indx] ;
        if(indx<0) return 0 ;
        if(dp[indx]!=-1) return dp[indx];
        
        int pick = arr[indx] + solve(indx-2,arr,dp);
        int notPick = solve(indx-1,arr,dp) ;
        
        return dp[indx] = max(pick,notPick) ;
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int ans = solve(n-1,nums,dp);
        return ans ;
    }
};