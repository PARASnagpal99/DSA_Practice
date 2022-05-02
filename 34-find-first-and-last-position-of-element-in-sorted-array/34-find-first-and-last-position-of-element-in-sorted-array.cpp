class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1 ;
        vector<int>res;
        int ans1 = -1 , ans2 = - 1;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            if(nums[mid]==target){
                ans1 = mid ;
                high = mid - 1 ;
            }
            
            if(nums[mid]>target){
                high = mid - 1 ;
            }
            
            if(nums[mid]<target){
                low = mid + 1 ;
            }
        }
        res.push_back(ans1);
        low = 0 , high = nums.size()-1 ;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            if(nums[mid]==target){
                ans2 = mid ;
                low = mid + 1 ;
            }
            
            if(nums[mid]>target){
                high = mid - 1 ;
            }
            
            if(nums[mid]<target){
                low = mid + 1 ;
            }
        }
        res.push_back(ans2) ;
        
        return res ;
    }
};