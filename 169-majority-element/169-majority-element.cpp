class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int var = 0 , count = 0 ;
        for(int i=0 ; i<n ; ++i){
             if(count==0){
                var = i ;
                count = 0 ;
            }
            
            if(nums[i]==nums[var]){
                count++;
            }else{
                count--;
            }
        }
        return nums[var] ;
        
    }
};