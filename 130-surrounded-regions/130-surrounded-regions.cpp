class Solution {
public:
    void dfs(vector<vector<char>>& grid , int i , int j){
        int m = grid.size() , n = grid[0].size() ;
        if(i<0 or j<0 or i>=m or j>=n) return ;
        if(grid[i][j]=='X' or grid[i][j]=='@') return ;
        grid[i][j] = '@' ;
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
    }

    void solve(vector<vector<char>>& grid) {
          int m = grid.size() , n = grid[0].size() ;
          for(int i=0 ; i<m ; ++i){
              if(grid[i][0]=='O'){
                  dfs(grid,i,0);
              }
              if(grid[i][n-1]=='O'){
                  dfs(grid,i,n-1);
              }
          }
        for(int i=0 ; i<n ; ++i){
              if(grid[0][i]=='O'){
                  dfs(grid,0,i);
              }
              if(grid[m-1][i]=='O'){
                  dfs(grid,m-1,i);
              }
          }
        
        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
                if(grid[i][j]=='@'){
                    grid[i][j]='O';
                }
            }
        }
    }
};