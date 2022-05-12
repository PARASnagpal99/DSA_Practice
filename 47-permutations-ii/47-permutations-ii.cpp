class Solution {
public:
    void func( set<vector<int>>&ans , vector<int>&temp , vector<int>&nums , int n ){
          if(temp.size()==n){
              ans.insert(temp);
              return ;
          } 
        for(int i=0 ; i<nums.size() ; ++i){
            int x = nums[i];
            if(x>10){
                continue ;
            }
            nums[i] = 100 ;
            temp.push_back(x);
            func(ans,temp,nums,n);
            nums[i] = x ;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>ans ;
        vector<int>temp ;
        func(ans,temp,nums,n);
        vector<vector<int>>res = vector<vector<int>>(ans.begin(),ans.end());
        return res ;
    }
};




/*


1 1 2 











*/
