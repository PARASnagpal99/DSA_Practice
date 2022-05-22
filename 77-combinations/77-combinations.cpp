class Solution {
public:
    void func(vector<vector<int>>&ans , vector<int> &temp , int indx , int k , int n ){
        if(temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=indx ; i<=n ; ++i){
            temp.push_back(i);
            func(ans,temp,i+1,k,n);
            temp.pop_back() ;
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans ;
        vector<int> temp ;
        func(ans,temp,1,k,n) ;
        return ans ;
    }
};