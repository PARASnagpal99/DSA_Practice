class Solution {
public:
//     int solve(int indx , vector<int>& arr , vector<int>& dp ){
//         if(indx==0) return arr[indx] ;
//         if(indx<0) return 0 ;
//         if(dp[indx]!=-1) return dp[indx];
        
//         int pick = arr[indx] + solve(indx-2,arr,dp);
//         int notPick = solve(indx-1,arr,dp) ;
        
//         return dp[indx] = max(pick,notPick) ;
        
//     }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0] ;
        int prev2 = 0 ;
        for(int i=1 ; i<n ; ++i){
            int pick = nums[i] ;
            if(i>1){
                pick+=prev2;
            }
            int nonPick = prev ;
            int curr = max(pick,nonPick);
            prev2 = prev ;
            prev = curr ;
        }
        return prev ;
    }
};