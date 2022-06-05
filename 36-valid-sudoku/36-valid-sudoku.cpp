class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size() ;
        map<int,unordered_set<char>> row , col , grid ;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(board[i][j]!='.'){
                    char val = board[i][j] ;
                    
                    if(row[i].count(val)) return false ;
                    if(col[j].count(val)) return false ;
                    
                    int box = 3*(i/3) + j/3 ;
                    if(grid[box].count(val)) return false ;
                    
                    grid[box].insert(val);
                    col[j].insert(val) ;
                    row[i].insert(val) ;
                }
            }
        }
        
        return true ;
    }
};