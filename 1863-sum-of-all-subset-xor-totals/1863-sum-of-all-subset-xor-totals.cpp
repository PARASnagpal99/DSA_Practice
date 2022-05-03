class Solution {
public:
    int res = 0 ;
    void func(vector<int>& nums , int curr , int indx){
        if(indx==nums.size()) {
              res+=curr ;
              return ;
        }
        func(nums,curr ^ nums[indx],indx+1);
        func(nums,curr,indx+1);
    }
    
    int subsetXORSum(vector<int>& nums) {
        func(nums,0,0);
        return res ;
    }
};