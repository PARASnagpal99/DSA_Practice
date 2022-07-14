class Solution {
    
public:
    int dp[500008][4] ;
    
    
    int func(int indx , int curr_row ,  vector<int> &nums){
        int n = nums.size() ;
        
        if(indx == n-1) return 0 ;
        
        if(dp[indx][curr_row]!=-1) return dp[indx][curr_row] ;
        
        if(nums[indx+1]!=curr_row){
            return dp[indx][curr_row] = func(indx+1,curr_row,nums) ;
        }
        
        int ans = INT_MAX ;
        
        for(int row=1 ; row<=3 ; ++row){
            
            if(row!=curr_row && row!=nums[indx]){
                ans = min(ans , 1 + func(indx,row,nums)) ;
            }
        }
        
        return dp[indx][curr_row] = ans ;
        
    }
    
    int minSideJumps(vector<int>& nums) {
        int n = nums.size() ;
        memset(dp,-1,sizeof(dp));
        int ans = func(0,2,nums) ;
        return ans ;
    }
};