class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>& grid){
        int n = grid.size() , m = grid[0].size() ;
        if(i<0 or j<0 or i>=n or j>=m) return ;
        if(grid[i][j]==0) return ;
        grid[i][j] = 0 ;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
//     int dfs1(int i , int j , vector<vector<int>>& grid){
//         int n = grid.size() , m = grid[0].size() ;
//         int cnt = 0 ;
//         if(i<0 or j<0 or i>=n or j>=m) return cnt ;
//         if(grid[i][j]==0) return cnt ;
//         grid[i][j] = 0 ;
//         cnt++;
//         return (cnt + dfs(i+1,j,grid) + 
//                       dfs(i,j-1,grid) + 
//                       dfs(i-1,j,grid) + 
//                       dfs(i,j+1,grid) 
//                );
        
//     }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        
        for(int i=0 ; i<n ; ++i){
            if(grid[i][0]){
                dfs(i,0,grid) ;
            }
            
            if(grid[i][m-1]){
                dfs(i,m-1,grid);
            }
        }
        
        for(int j=0 ; j<m ; ++j){
            if(grid[0][j]){
                dfs(0,j,grid) ;
            }
            
            if(grid[n-1][j]){
                dfs(n-1,j,grid);
            }
        }
        
        
        
        
        
        
        int ans = 0 ;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j]) ans++ ;
            }
        }
        return ans ;
    }
};