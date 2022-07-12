class Solution {
public:
    int dp[1 << 16][4] ;
    int func(int mask , vector<int> &nums , int currsum , int target , int count){
        int n = nums.size() ;
        
        if(count == 0) return 1 ;
        
        if(dp[mask][count]!=-1) return dp[mask][count] ;
        
        if(currsum == target){
            return dp[mask][count] = func(mask,nums,0,target,count-1);
        }
        
        
        for(int i=0 ; i<n ; ++i){
            if((mask & (1 << i)) or currsum + nums[i] > target) continue ;
            
            if(func(mask | (1 << i) , nums , currsum + nums[i] , target , count)){
                return dp[mask][count] = 1 ;
            }
            
        }
        
        return dp[mask][count] = 0 ;
    }

        
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size() ;
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4 or n < 4) return false ;
        memset(dp,-1,sizeof(dp));
        int target = sum/4 ;
        int ans = func(0,matchsticks,0 , target,3);
        return ans ;
    }
};