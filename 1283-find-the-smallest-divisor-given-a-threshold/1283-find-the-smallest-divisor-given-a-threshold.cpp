class Solution {
public:
    bool isValid(vector<int>&nums , int curr , int target){
        int sum = 0 ;
        for(auto &it : nums){
            sum += (it/curr) ;
            if(it%curr) sum+=1 ;
        }
        return sum<=target ;
    }
    
    int smallestDivisor(vector<int>& nums, int k) {
        int lo = 1 , hi = 1000000 ;
        int ans ;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            if(isValid(nums,mid,k)){
                ans = mid ;
                hi = mid-1 ;
            }else{
                lo = mid+1 ;
            }
        }
       
        return ans ;
        
    }
};