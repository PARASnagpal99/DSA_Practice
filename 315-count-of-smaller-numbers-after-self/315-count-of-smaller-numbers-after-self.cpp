#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>


class Solution {
public:    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n) ;
        ordered_set st ;
        int indx = n-1 ;
        
        while(indx >= 0){
            st.insert(nums[indx]);
            int cnt = st.order_of_key(nums[indx]) ;
            ans[indx] = cnt ;
            indx--;
        }
        
        
        return ans ;
    }
};