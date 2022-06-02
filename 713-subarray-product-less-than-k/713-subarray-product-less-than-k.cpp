class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(k<=1){
            return 0 ;
        }
        int cnt = 0 ;
        int product = 1 ;
        int end = 0 , start = 0 ;
        
        while(end<n){
            product*=nums[end] ;
            while(product>=k){
                product = product/nums[start] ;
                start++;
            }
            cnt+=(end-start+1) ;
            end++;
        }
        
        return cnt ;
        
    }
};