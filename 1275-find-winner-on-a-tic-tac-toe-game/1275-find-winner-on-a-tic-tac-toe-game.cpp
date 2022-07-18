class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
    
        vector<vector<int>> game(3,vector<int>(3,0)) ;
        
        
        for(int i=0 ; i<moves.size() ; ++i){
            if(i % 2 == 0){
                game[moves[i][0]][moves[i][1]] = 1 ;
            }else{
                game[moves[i][0]][moves[i][1]] = 2 ;
            }
            
        }
        
        
        for(int i=0 ; i<3 ; ++i){
            int cnt_one = 0 ;
            int cnt_two = 0  ;
            for(int j=0 ; j<3 ; ++j){
                if(game[i][j] == 1) cnt_one++;
                if(game[i][j] == 2) cnt_two++;
            }
            if(cnt_one == 3) return "A" ;
            if(cnt_two == 3) return "B" ;
        }
        
        for(int j=0 ; j<3 ; ++j){
            int cnt_one = 0 ;
            int cnt_two = 0  ;
            for(int i=0 ; i<3 ; ++i){
                if(game[i][j] == 1) cnt_one++;
                if(game[i][j] == 2) cnt_two++;
            }
            if(cnt_one == 3) return "A" ;
            if(cnt_two == 3) return "B" ;
        }
        
        
       
        // checking for diagonals ;
        int one = 0 , two = 0 ;
        if(game[0][0] == 1) one++;
        if(game[0][0] == 2) two++;
        if(game[1][1] == 1) one++;
        if(game[1][1] == 2) two++;
        if(game[2][2] == 2) two++;
        if(game[2][2] == 1) one++;
            
            
        if(one == 3) return "A" ;
        if(two == 3) return "B" ;
        
        
        one = 0 , two = 0 ;
        
        if(game[0][2] == 1) one++;
        if(game[0][2] == 2) two++;
        if(game[2][0] == 1) one++;
        if(game[2][0] == 2) two++;
        if(game[1][1] == 1) one++;
        if(game[1][1] == 2) two++;
        
        if(one == 3) return "A" ;
        if(two == 3) return "B" ;
        
        
        
        
        if(moves.size() == 9) return "Draw" ;
        
        return "Pending" ;
        
        
    }
};