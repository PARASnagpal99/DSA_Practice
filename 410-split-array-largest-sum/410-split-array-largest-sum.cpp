class Solution {
public:
    bool isValid(vector<int>& nums , int m , int mid){
        int sub_count = 1 , value = 0 ;
        for(int i=0 ; i<nums.size() ; ++i){
            if(value > mid) return false ;
            if(nums[i] + value > mid){
                sub_count++;
                value = nums[i] ;
            }else{
                value+=nums[i] ;
            }
        }
        return (sub_count<=m) ;
    }
    
    
    
    int splitArray(vector<int>& nums, int m) {
        int ans = INT_MAX ;
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0) ;
        while(lo<=hi){
            int mid = (lo + hi) >> 1 ;
            if(isValid(nums,m,mid)){
                ans = mid ;
                hi = mid -1 ;
            }else{
                lo = mid + 1;
            }
        }
        return ans ;
    }
};