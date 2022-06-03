class Solution {
public:
    bool isValid(vector<int>&nums , int sz , int target){
        int sum = 0 ;
        for(int i=0 ; i<nums.size() ; ++i){
            sum+=nums[i] ;
            if(i>=sz) sum-=nums[i-sz] ;
            if(sum>=target) return true ;
        }
        return false ;
    }
    
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 1 , right = nums.size() ;
        int len = 0 ;
        while(left<=right){
            int mid = (left+right)/2 ;
            if(isValid(nums,mid,target)){
                len = mid ;
                right = mid-1 ;
            }else{
                left =  mid+1 ;
            }
        }
        return len ;
    }
};