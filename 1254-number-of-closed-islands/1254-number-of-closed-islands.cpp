class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>& grid){
        int n = grid.size() , m = grid[0].size() ;
        if(i<0 or j<0 or i>=n or j>=m) return ;
        if(grid[i][j]) return ;
        grid[i][j] = 1 ;
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        for(int i=0 ; i<n ; ++i){
            if(!grid[i][0]){
                dfs(i,0,grid);
            }
            if(!grid[i][m-1]){
                dfs(i,m-1,grid);
            }
        }
        
        for(int j=0 ; j<m ; ++j){
            if(!grid[0][j]){
                dfs(0,j,grid);
            }
            if(!grid[n-1][j]){
                dfs(n-1,j,grid);
            }
        }
        
        int cnt = 0 ;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(!grid[i][j]){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        
        return cnt ;
     }
};