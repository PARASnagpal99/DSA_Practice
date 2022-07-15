class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>&grid , int &count){
        int n = grid.size() , m = grid[0].size() ;
        if(i < 0 or j < 0 or i>=n or j>=m or grid[i][j] == 0) return ; 
        count++;
        grid[i][j] = 0 ;
        dfs(i,j+1,grid,count);
        dfs(i+1,j,grid,count);
        dfs(i,j-1,grid,count);
        dfs(i-1,j,grid,count);
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        
        int mx_area = 0 ;
        
        int cnt ;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j]){
                    cnt = 0 ;
                    dfs(i,j,grid,cnt) ;
                    mx_area = max(mx_area,cnt) ;
                }
            }
        }
        
        
        return mx_area ;
        
    }
};