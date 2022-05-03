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
    
    int coinChange(vector<int>& arr, int amount) {
          int n = arr.size() ;
          vector<vector<int>>dp(n,vector<int>(amount+1,0));
          for(int i=0 ; i<=amount ; ++i){
              if(i%arr[0]==0){
                  dp[0][i] = i/arr[0] ;
              }else{
                  dp[0][i] = 1e9 ;
              }
          }
       
         for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=amount; target++){
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
        
        int ans = dp[n-1][amount] ;
        if(ans>=1e9) return -1 ;
        return ans ;
        
    }
};