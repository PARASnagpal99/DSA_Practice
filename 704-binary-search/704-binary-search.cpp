class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1 ;
        int n = nums.size() ;
        int left = 0 , right = n-1 , mid ;
        while(left<=right){
            mid = left + (right-left)/2 ;
            if(nums[mid]==target){
                ans = mid ;
                break ;
            }else if(nums[mid]>target){
                right = mid-1 ;
            }else{
                left = mid+1 ;
            }
        }
        return ans ;
    }
};