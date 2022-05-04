class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size() ;
        int left = 0 , right = n-1 ;
        int count = 0 ;
        sort(nums.begin(),nums.end());
        while(left<right){
            if(nums[left]+nums[right]==k){
                count++;
                left++;
                right--;
            }else if(nums[left]+nums[right]>k){
                right--;
            }else{
                left++;
            }
        }
        return count ;
    }
};