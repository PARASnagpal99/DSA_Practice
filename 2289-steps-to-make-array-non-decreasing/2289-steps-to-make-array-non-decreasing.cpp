class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size() ;
        if(is_sorted(nums.begin(),nums.end())) return 0 ;
        vector<pair<int,int>>stk ;
        int ans = 0 ;
        stk.push_back({nums[n-1],0}) ;
        for(int i=n-2 ; i>=0 ; i--){
            int cnt = 0 ;
            while(!stk.empty() && nums[i]>stk.back().first){
                cnt = max(cnt+1,stk.back().second) ;
                stk.pop_back() ;
            }
            ans = max(cnt,ans);
            stk.push_back({nums[i],cnt});
        }
        return ans ;
    }
};