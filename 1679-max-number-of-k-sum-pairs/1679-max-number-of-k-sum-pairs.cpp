class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size() ;
        map<int,int>mp ;
        for(auto &it : nums){
            mp[it]++;
        }
        int count = 0 ;
        for(auto &it : mp){
            int num = it.first , freq = it.second ;
            if(num==k-num) count+=(freq/2);
            else if(mp.find(k-num)!=mp.end()){
                int x = min(mp[num] , mp[k-num]);
                count+=x ;
                mp[num]-=x;
                mp[k-num]-=x;
            }
        }
        return count ;
    }
};