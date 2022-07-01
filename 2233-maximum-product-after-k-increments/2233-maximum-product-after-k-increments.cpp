class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
         multiset<int> st(nums.begin(),nums.end());
         int mod = 1e9 + 7 ;
        
        while(k--){
            auto curr = *st.begin() ;
            st.erase(st.begin()) ;
            st.insert(curr + 1) ;
        }
        
        long long ans = 1 ;
        for(auto &it : st){
            ans = ( ( ans % mod) * (it % mod) ) % mod ; 
        }
        
        return (int)ans ;
        
    }
};