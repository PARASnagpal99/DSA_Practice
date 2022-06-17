class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size() ;
        int len = 1 ;
        int i = 1 ;
        int ans = 1 ;
        while(i < n){
            if(nums[i-1] < nums[i]){
                len++;
                ans = max(len,ans) ;
            }else{
                len = 1 ;
            }
            i++;
        }
        return ans ;
    }
};