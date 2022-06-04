class Solution {
public:
    bool isSafe(int i , int j , vector<string>& temp){
        
        for(int x = 0 ; x<i ; ++x){
            for(int y=0 ; y<(int)temp.size() ; ++y){
                if(temp[x][y]=='Q'){
                    if(j==y or abs(x-i)==abs(y-j)) return false ;
                }
            }
        }
        return true ;
    }
    
    
    void dfs(int i , vector<string> &temp , vector<vector<string>>&res){
        int n = temp.size() ;
        if(i==n){
            res.push_back(temp) ;
        }
        
        for(int j=0 ; j<n ; ++j){
            if(isSafe(i,j,temp)){
                temp[i][j] = 'Q' ;
                dfs(i+1,temp,res);
                temp[i][j] = '.' ;
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res ;
        vector<string> temp(n,string(n,'.')) ;
        dfs(0,temp,res);
        return res ;
    }
};