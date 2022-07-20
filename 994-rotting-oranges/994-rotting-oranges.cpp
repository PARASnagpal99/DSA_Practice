class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        
        int time = -1 ;
        
        int oranges = 0 ;
        
        queue<pair<int,int>>q ;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } 
                
                if(grid[i][j] == 1) oranges++;
                
            }
        }
        
        
        vector<pair<int,int>> dirs = {{1,0} , {-1,0} , {0,1} , {0,-1}} ;
    
        
        while(!q.empty()){
            int sz = q.size() ;
            time++;
            for(int i=0 ; i<sz ; ++i){
                auto [x,y] = q.front() ;
                q.pop() ;
                for(auto &it : dirs){
                    int nx = x + it.first ;
                    int ny = y + it.second ; 
                    if(nx >=0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == 1){
                        oranges--;
                        grid[nx][ny] = 2 ;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        if(oranges > 0) return -1 ;
        
        if(time == -1) return 0 ;
        
        return time ;
        
    }
};