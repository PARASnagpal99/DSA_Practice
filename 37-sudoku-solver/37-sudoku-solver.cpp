class Solution {
public:
    bool isValid(vector<vector<char>>& board , int x , int y , int c ){
        
        for(int i=0 ; i<9 ; ++i){
            
            if(board[x][i]==c+'0') return false ;
            
            if(board[i][y]==c+'0') return false ;
            
        }
        
        
        int key = 3*(x/3) + y/3 ;
        
        for(int i=0 ; i<9 ; ++i){
            
            for(int j=0 ; j<9 ; ++j){
                
                int dummy = 3*(i/3) + j/3 ;
                if(dummy==key){
                    if(board[i][j]==c+'0') return false ;
                }
                
            }
        }
        
        return true ;
    }
    
    
    
    bool func(vector<vector<char>>& board , int i , int j){
        if(i==8 && j==9) return true ;
        if(j==9) return func(board,i+1,0) ;
        
        if(board[i][j]!='.') return func(board,i,j+1);
        
        for(int k=1 ; k<=9 ; ++k){
            
            if(isValid(board,i,j,k)){
                board[i][j] = k + '0' ;
                if(func(board,i,j+1)) return true ; 
                board[i][j] = '.' ;
            }
            
        }
        
        return false ;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
          func(board,0,0);
    }
};