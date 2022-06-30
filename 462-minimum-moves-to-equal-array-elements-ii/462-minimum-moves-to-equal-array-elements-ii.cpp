class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(),nums.end());
        int target = nums[n/2];
        int cnt = 0 ;
        for(auto &it : nums){
            cnt += abs(it - target) ;
        }
        
        return cnt ;
    }
};