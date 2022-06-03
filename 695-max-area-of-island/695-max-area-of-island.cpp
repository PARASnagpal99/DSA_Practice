class Solution {
public:
    int dfs(int i , int j , vector<vector<int>>& grid){
        int m = grid.size() , n = grid[0].size() ;
        if(i<0 or j<0 or i>=m or j>=n) return 0  ;
        if(grid[i][j]==0) return 0 ;
        grid[i][j] = 0 ;
        int cnt = 1 ;
        cnt+= dfs(i,j+1,grid);
        cnt+= dfs(i,j-1,grid);
        cnt+= dfs(i+1,j,grid);
        cnt+= dfs(i-1,j,grid);
        
        return cnt ;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        int count = 0 ;
        for(int i=0  ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(grid[i][j]){
                    int cnt = dfs(i,j,grid);
                    count = max(count,cnt);
                }
            }
        }
        return count ;
    }
};