class Solution {
public:
//     int func(int indx , vector<int>&nums , int k , vector<int> &dp ){
//         int n = nums.size() ;
        
//         if(indx == 0){
//             return nums[indx] ;
//         }
        
//         if(indx < 0){
//             return (-1 * 1e9 + 5);
//         }
        
//         if(dp[indx] != -1 ) return dp[indx] ;
        
//         int ans = -1e9 + 5 ;
        
//         for(int i=1 ; i<=k ; ++i){
//             int res = nums[indx] + func(indx-i,nums,k,dp) ;
//             ans = max(ans,res) ;
//         }
        
//         return dp[indx] = ans ;
//     }
    
    
    
    
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> dp(n,-1*1e9) ;
        
        dp[0] = nums[0] ;
        multiset<int> st ;
        st.insert(dp[0]);
        
        for(int i=1 ; i<n ; ++i){
            
            if(i > k){
                 auto it = st.find(dp[i-k-1]) ;
                 if(it!=st.end()) st.erase(it) ;
            }
            auto it = st.end() ;
            it--;
            dp[i] = *it + nums[i] ;
            
            st.insert(dp[i]) ;
            
        }
        
        return dp[n-1] ;
        
    }
};