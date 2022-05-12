class Solution {
public:
    void func( vector<vector<int>>&ans , vector<int>&temp , unordered_map<int,int> &s , int n ){
          if(temp.size()==n){
              ans.push_back(temp);
              return ;
          } 
        for(auto &it : s){
            if(it.second<=0){
                continue ;
            }
            it.second--;
            temp.push_back(it.first);
            func(ans,temp,s,n);
            it.second++;
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans ;
        vector<int>temp ;
        unordered_map<int,int>s ;
        for(auto &it : nums){
            s[it]++;
        }
        func(ans,temp,s,n);
        return ans ;
    }
};




/*


1 1 2 











*/
