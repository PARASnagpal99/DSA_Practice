class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        int left = 0 , right = n-1 ;
        while(left<right){
            int mid = left + (right-left)/2 ;
            if((mid!=0 && mid!=n-1 && nums[mid]!=nums[mid+1] && nums[mid-1]!=nums[mid]) or (mid==0 && nums[mid]!=nums[mid+1]) or (mid==n-1 &&                           nums[mid]!=nums[mid-1])){
                return nums[mid] ;
            }else if((mid&1 && nums[mid-1]==nums[mid]) or (mid%2==0 && nums[mid]==nums[mid+1])){
                left = mid + 1 ;
            }else{
                right = mid - 1   ;
            }
        }
        
        return nums[right] ;
        
        
    }
};