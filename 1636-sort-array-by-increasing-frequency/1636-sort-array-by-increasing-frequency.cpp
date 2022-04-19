class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size() ;
        map<int,int>hsh ;
        for(auto &it : nums){
            hsh[it]++;
        }
        sort(nums.begin(),nums.end(),[&](int a , int b){
            if(hsh[a]==hsh[b]){
                return a>b ;
            }else{
                return hsh[a]<hsh[b];
            }
        }) ;
        
        return nums ;
    }
};