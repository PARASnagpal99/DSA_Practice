class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.empty()) return true ;
        vector<int> nums(n+1,0) ;
        for(auto &it : trust){
            nums[it[0]]--;
            nums[it[1]]++;
        }
        int ans = -1 ;
        for(int i=1 ; i<=n ; ++i){
            if(nums[i]==n-1){
                ans = i ;
            }
        }
         
        return ans ;
    }
};