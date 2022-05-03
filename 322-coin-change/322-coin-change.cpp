class Solution {
public:
    int func(vector<int>& arr ,  vector<vector<int>>&dp , int target , int indx){
        if(indx==0){
            if(target%arr[indx]==0){
                return target/arr[indx] ;
            }else{
                return 1e9 ;
            }
        }
        
        if(dp[indx][target]!=-1) return dp[indx][target] ;
        
        int notTaken = 0 + func(arr,dp,target,indx-1);
        int taken = 1e9 ;
        if(target>=arr[indx]){
            taken = 1 + func(arr,dp,target-arr[indx],indx);
        }
        return dp[indx][target] = min(taken,notTaken) ;
    }
    
    int coinChange(vector<int>& coins, int amount) {
          int n = coins.size() ;
          vector<vector<int>>dp(n,vector<int>(amount+1,-1));
          int ans = func(coins,dp,amount,n-1);
          if(ans>=1e9) return -1 ;
          return ans ;
    }
};