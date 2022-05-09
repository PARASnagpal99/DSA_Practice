class Solution {
public:
    bool isSafe(vector<string>&temp , int i , int j){
        int n = temp.size() ;
        for(int x=0 ; x<i ; ++x){
            for(int y=0 ; y<n ; ++y){
                if(temp[x][y]=='Q'){
                     if(y==j or (abs(x-i)==abs(y-j))){
                    return false ;
                   }
                }
            }
        }
        return true ;
    }
    
    void func(int i , int n , vector<string>&temp , vector<vector<string>>&ans){
         if(i==n){
             ans.push_back(temp);
             return ;
         }
        for(int j=0 ; j<n ; ++j){
            if(isSafe(temp,i,j)){
                temp[i][j] = 'Q' ;
                func(i+1,n,temp,ans);
                temp[i][j] = '.' ; // backtrack 
            }
        }
        return ;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans ;
        vector<string>temp(n,string(n,'.'));
        func(0,n,temp,ans);
        return ans ;
    }
};