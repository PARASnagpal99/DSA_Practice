class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>res ;
        map<int,int>mp;
        for(auto &it : nums){
            for(auto &t : it){
                mp[t]++;
            }
        }
        for(auto &it : mp){
            if(it.second==n){
                res.push_back(it.first);
            }
        }
        return res ;
    }
};