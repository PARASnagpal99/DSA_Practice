class Solution {
public:
    void func(int indx , vector<int>&temp , vector<vector<int>>&ans , int k , int n){
        if(n<0 or k<0) return ;
        
        if(k==0 && n==0){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=indx ; i<=9 ; ++i){
            temp.push_back(i);
            func(i+1,temp,ans,k-1,n-i);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans ;
        vector<int>temp ;
        func(1,temp,ans,k,n);
        return ans ;
    }
};