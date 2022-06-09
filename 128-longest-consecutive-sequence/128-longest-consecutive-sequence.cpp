class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if(nums.size()==0) return 0 ;
        int res = 1 , count = 1 ;
        sort(nums.begin(),nums.end());
        
        for(int i=1 ; i <nums.size() ; ++i){
            if(nums[i]==nums[i-1]) continue ;
            else if(nums[i]==nums[i-1]+1){
                   count++;
            }else{
                res = max(res,count);
                count = 1 ;
            }
        }
        
        return max(res,count) ;
    }
};