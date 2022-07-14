class Solution {
public:
    #define ll long long 
    
    ll dp[100005] ;
    
    ll func(int indx , vector<vector<int>>& nums ){
        int n = nums.size() ;
        if(indx >= n) return 0 ;
        if(dp[indx]!=-1) return dp[indx] ;
        
        ll res = 0 ;
        
        ll answer = (nums[indx][0] + func(nums[indx][1] + indx + 1 , nums )) ;
        ll skip  = func(indx+1,nums) ;
        
        res = max(answer,skip) ;
        
        return dp[indx] = res ;
    }
    
    
    
    long long mostPoints(vector<vector<int>>& nums) {
        int n = nums.size() ;
        memset(dp,-1,sizeof(dp));
        ll res = func(0,nums) ;
        return res ;
    }
};