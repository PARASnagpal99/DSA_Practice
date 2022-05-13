class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int cnt1 = 0 , cnt2 = 0 ;
        int num1 = -1 , num2 = -1 ;
        for(auto &it : nums){
            if(it==num1) cnt1++;
            else if(it==num2) cnt2++;
            else if(cnt1==0) cnt1 = 1  , num1 = it ;
            else if(cnt2==0) cnt2 = 1 , num2 = it ;
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0 , cnt2 = 0 ;
        for(auto &it : nums){
            if(it==num1) cnt1++;
            else if(it==num2) cnt2++;
        }
        vector<int>res ;
        if(cnt1>n/3) res.push_back(num1);
        if(cnt2>n/3) res.push_back(num2);
        return res ;
    }
};