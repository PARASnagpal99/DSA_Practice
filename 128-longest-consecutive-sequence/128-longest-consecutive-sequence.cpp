class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(),nums.end());
        if(n==0) return 0 ;
        if(n==1) return 1 ;
        
        unordered_set<int> st ;
        int ans = 0 ;
        st.insert(nums[0]) ;
        
        for(int i=1 ; i<n ; ++i){
            if(nums[i] != nums[i-1] && nums[i]!=nums[i-1] + 1){
                st.clear() ;
            }
            st.insert(nums[i]) ;
            int sz = st.size() ;
            ans = max(sz,ans);
        }
        
        
        return ans ;
        
        
        
        
    }
};