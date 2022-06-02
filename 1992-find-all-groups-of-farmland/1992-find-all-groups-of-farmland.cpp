class Solution {
public:
    vector<pair<int,int>>dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    void bfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& res){
        int n = grid.size() , m = grid[0].size() ;
        int x = -1 , y = -1 ;
        grid[i][j] = 0 ;
        queue<pair<int,int>>q ;
        q.push({i,j});
        
        while(!q.empty()){
            auto curr = q.front() ;
            q.pop() ;
            x = curr.first ;
            y = curr.second ;
            
            for(auto it : dirs){
                int newX = x + it.first ;
                int newY = y + it.second ;
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]){
                    grid[newX][newY] = 0 ;
                    q.push({newX,newY});
                }
            }
            
        }
        res.push_back({i,j,x,y});
    }
    
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size() , m = land[0].size() ;
        vector<vector<int>>res ;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(land[i][j]==1){
                    bfs(i,j,land,res);
                }
            }
        }
        return res ;
    }
};