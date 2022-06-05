class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int prev_min1 = INT_MAX  , prev_min2 = INT_MAX ;
        for(int i=0 ; i<nums.size() ; ++i){
            if(nums[i] > prev_min2 && prev_min2 > prev_min1) return true ;
            
            if(nums[i] < prev_min1){
                prev_min1 = nums[i] ; 
            }else if(nums[i] > prev_min1 && prev_min2 > nums[i]){
                prev_min2 = nums[i] ;
            }
        } 
       
        return false ;
        
        
    }
};