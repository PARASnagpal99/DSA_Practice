class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>& grid){
        int n = grid.size() , m = grid[0].size() ;
        if(i<0 or j<0 or i>=n or j>=m) return ;
        if(grid[i][j]==0) return ;
        grid[i][j] = 0 ;
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i-1,j,grid);
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
          int n = grid1.size() , m = grid1[0].size() ;
          for(int i=0 ; i<n ; ++i){
              for(int j=0 ; j<m ; ++j){
                  if(grid1[i][j]==0 && grid2[i][j]==1){
                      dfs(i,j,grid2);
                  }
              }
          }
        
        int cnt = 0 ;
         for(int i=0 ; i<n ; ++i){
              for(int j=0 ; j<m ; ++j){
                  if(grid2[i][j]==1){
                      dfs(i,j,grid2);
                      cnt++;
                  }
              }
          }
        
        return cnt ;
        
        
        
        
    }
};