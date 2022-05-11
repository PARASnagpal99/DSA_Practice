class Solution {
public:
    void func(vector<vector<char>>&res , vector<char>&temp , int indx , vector<char> &arr , int n){
        if(temp.size()==n){
            res.push_back(temp);
            return ;
        }
        
        for(int i=indx ; i<arr.size() ; ++i){
            temp.push_back(arr[i]);
            func(res,temp,i,arr,n);
            temp.pop_back();
        }
    }
    
    int countVowelStrings(int n) {
          vector<char> arr = {'a','e','i','o','u'};
          vector<vector<char>>res ;
          vector<char>temp ;
          func(res,temp,0,arr,n);
          return res.size() ;
    }
};