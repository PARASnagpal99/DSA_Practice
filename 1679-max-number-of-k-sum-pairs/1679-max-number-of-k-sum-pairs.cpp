class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size() ;
        map<int,int>mp ;
        int count = 0 ;
        for(int i=0 ; i<n ; ++i){
            int x = nums[i] ;
            if(mp[k-x]>0){
                count++;
                mp[k-x]--;
            }else{
                mp[x]++;
            }
        }
        return count ;
    }
};