class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size() ;
        unordered_set<int> st ;
        int sum = 0 ;
        int ans = 0 ;
        int start = 0 , end = 0 ;
        while(end < n)  {
            sum+=nums[end] ;
            
            while(st.find(nums[end])!=st.end()){
                  sum-=nums[start] ;
                  st.erase(nums[start]) ;
                  start++;
            }
            
            if(st.find(nums[end])==st.end()){
                st.insert(nums[end]);
                ans = max(ans,sum) ;
            }
            
            end++;
        }
        
        return ans ;
    }
};