class Solution {
public:
    
    bool func(int ind , int target , vector<int>&nums , vector<vector<int>>&dp){
        if(target==0) return 0 ;
        if(ind==0){
            return nums[0]==target ;
        }
        if(dp[ind][target]!=-1) return dp[ind][target] ;
        bool notTaken = func(ind-1,target,nums,dp);
        bool taken = false ;
        if(nums[ind]<=target){
            taken = func(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target] = taken||notTaken ;
    }
    
    
    bool canPartition(vector<int>& arr) {
     int n = arr.size() ;
     int sum =  accumulate(arr.begin(),arr.end(),0);
     if(sum&1) return false ;
     int target = sum/2 ;
     vector<vector<int>>dp(n,vector<int>(target+1,-1));
     return func(n-1,target,arr,dp);
//      int k = sum/2 ;
//      vector<vector<bool>>dp(n,vector<bool>(k+1,false));
//      for(int i=0 ; i<n ; ++i){
//           dp[i][0] = true ;   
//       } 
//       dp[0][arr[0]] = true ;
      
//       for(int ind=1 ; ind<n ; ++ind){
//           for(int target=1 ; target<=k ; ++target){
//               bool notTaken = dp[ind-1][target];
//               bool taken = false ;
//               if(arr[ind]<=target){
//                   taken = dp[ind-1][target-arr[ind]];
//               }
//               dp[ind][target] = notTaken || taken ;
//           }
//       }
        
//        return dp[n-1][k] ; 
    }
};