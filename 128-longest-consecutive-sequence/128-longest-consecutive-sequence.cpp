class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(),nums.end());
        if(n==0) return 0 ;
        if(n==1) return 1 ;
        
        int ans = 1 ;
        int count = 1 ;
        
        for(int i=0 ; i<n-1 ; ++i){
            if(nums[i+1]==nums[i]+1) count++;
            else if(nums[i]==nums[i+1]) continue ;
            else{
                count = 1 ;
            }
            ans = max(ans,count);
        }
        
        return ans ;
        
        
        
        
        
        
        
        
        return ans ;
        
        
        
        
    }
};