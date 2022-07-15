class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size() ;
        
        vector<pair<int,int>> stk ;
        
        stk.push_back({nums[0],0});
        
        for(int i=1 ; i<n ; ++i){
            int curr = stk.back().first ;
            int indx = stk.back().second ;
            if(indx % 2 == 0 && curr == nums[i]) continue ;
            stk.push_back({nums[i],indx+1});
        }
        
        // for(auto &it : stk){
        //     cout << it.first << " " ;
        // }
        // cout << endl ;
        
        int sz = stk.size() ;
        int cnt = n - stk.size() ;
        if(sz % 2 == 0){
            return cnt ;
        }
        
        return cnt + 1 ;
    }
};