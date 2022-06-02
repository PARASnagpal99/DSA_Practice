class Solution {
public:
    /*
    2 3 -2 4
    mx = 2 , mn = 2      ans = 2
    mx = 6 , mn = 3      ans = 6 
    mx = -2 , mn = -12   ans = 6
    mx = -8 , mn = -48   ans = 6
    
    
    */
    int maxProduct(vector<int>& nums) {
         int n = nums.size() ;
         int mx = nums[0] , mn = nums[0] , ans = INT_MIN ;
         ans = max(ans,mx) ;
         for(int i=1 ; i<n ; ++i){
             if(nums[i]<0) swap(mx,mn) ;
             
             mx = max(nums[i],nums[i]*mx);
             mn = min(nums[i],nums[i]*mn);
             
             ans = max(mx,ans) ;
             ans = max(mn,ans) ;
         }
        
        return ans ;
    }
};