class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt = 0 , n = nums.size() ;
        for(int i=1 ; i<n ; ++i){
            if(nums[i]<=nums[i-1]){
                cnt++ ;
                if(i>1 && nums[i-2]>=nums[i]){
                    nums[i] = nums[i-1] ;
                }
            }
        }
        return cnt<=1 ;
    }
};