class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        
        int first = lower_bound(nums.begin(),nums.end(),target) - nums.begin() ;
        int second = upper_bound(nums.begin(),nums.end(),target) - nums.begin() ;
        second-- ;
        
        if(first < n && nums[first] == target){
            return {first,second} ;
        } 
        
        return {-1,-1} ;
        
        
    }
};