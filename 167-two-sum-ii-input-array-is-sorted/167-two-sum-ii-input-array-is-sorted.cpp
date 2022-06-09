class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size() ;
        int left = 0 , right = n-1 ;
        while(left<right){
            int val = nums[left] + nums[right] ;
            if(val==target){
                return {left+1,right+1} ;
            }
            
            if(nums[left]+nums[right]>target){
                right--;
            }else{
                left++;
            }
        }
        
        return {-1,-1} ;
        
    }
};