class Solution {
public:
    void func(int n , int val , int &x , int &y){
        x = n - 1 - (val-1)/n  ;
        y = (val-1)%n ;
        
        if((n%2 == x%2)){
            y = n-1-y ;
        }
    }
    

    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size() ;
        unordered_set<int> visited ;
        visited.insert(1);
        queue<pair<int,int>>q ;
        q.push({1,0}) ;
        
        while(!q.empty()){
            
            auto curr = q.front() ;
            q.pop() ;
            
            int val = curr.first , dist = curr.second ;
            
            if(val == n*n) return dist ;
            
            int x , y ;
            
            for(int i=1 ; val + i <= (n*n) && i<=6 ; ++i){
                func(n,val + i , x , y) ;
                int newVal ;
                if(board[x][y] == -1){
                    newVal = val + i ;
                }else{
                    newVal = board[x][y] ;
                }
                
                if(visited.find(newVal) == visited.end()){
                    visited.insert(newVal) ;
                    q.push({newVal,dist+1});
                }
            }
            
        }
        
        return -1 ;
        
    }
};