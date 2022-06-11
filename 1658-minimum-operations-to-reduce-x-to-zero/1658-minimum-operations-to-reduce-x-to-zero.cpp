class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size() ;
        
        int s = accumulate(nums.begin(),nums.end(),0) ;
        if(x==s) return n ;
        if(x > s) return -1 ;
        int target = s - x ;
        int start = 0 , end = 0 ;
        int sum = 0 ;
        int len = 0 ;
        while(end < n){
            sum+=nums[end] ;
            while(sum > target){
                sum-=nums[start] ;
                start++;
            }
            
            if(sum == target){
                len = max(len , end-start+1);
            }
            end++;
        }
        if(len==0) return -1 ;
        
        int ans = n-len ;
        return ans ;
    }
};