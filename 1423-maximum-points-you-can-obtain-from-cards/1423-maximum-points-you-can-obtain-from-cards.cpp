class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size() ;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int start = 0 , end = 0 ;
        
        int curr_sum = 0 ;
        for(int i=0 ; i<(n-k) ; ++i) curr_sum += nums[i] ;
        end = n-k ;
        
        
        int res = curr_sum ;
        
        while(end < n){
            curr_sum+=nums[end] ;
            curr_sum-=nums[start];
            start++;
            end++;
            res = min(curr_sum , res) ;
        }
        
        return (sum - res);
        
    }
};