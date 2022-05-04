class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0 ;
        int m = grid.size() , n = grid[0].size() ;
        int freshOranges = 0 ;
        queue<pair<int,int>>q ;
        
        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j){
                
                if(grid[i][j]==1) freshOranges++;
                
                if(grid[i][j]==2){
                    q.push({i,j});  // multi source bfs  , push all the sources
                }
            }
        }
        
        
        int res = 0 ;
        
        vector<pair<int,int>>directions = {{0,1} , {1,0} , {-1,0} , {0,-1} };
        while(!q.empty() && freshOranges!=0){
            int size = q.size() ;
            for(int i=0 ; i<size ; ++i){
                int x = q.front().first ;
                int y = q.front().second ;
                q.pop() ;
                for(auto &it : directions){
                    int newx = x + it.first ;
                    int newy = y + it.second ;
                    if(newx>=0 && newy>=0 && newx<m && newy<n && grid[newx][newy]==1){
                        grid[newx][newy] = 2 ;
                        freshOranges--;
                        q.push({newx,newy});
                    }
                }
            }
            res++;
        }
        if(freshOranges==0) return res ;
        else return -1 ;
        
        
    }
};