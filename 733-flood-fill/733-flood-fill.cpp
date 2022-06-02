class Solution {
public:
    void dfs(vector<vector<int>>& grid , int i , int j , int org , int New){
        int n = grid.size() , m = grid[0].size() ;
        if(i<0 or j<0 or i>=n or j>=m) return ;
        if(grid[i][j]!=org) return ;
        grid[i][j] = New ;
        dfs(grid,i+1,j,org,New);
        dfs(grid,i-1,j,org,New);
        dfs(grid,i,j+1,org,New);
        dfs(grid,i,j-1,org,New);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int originalColor = image[sr][sc] ;
         if(newColor!=originalColor){
              dfs(image,sr,sc,originalColor,newColor) ;
         }
         return image ;
    }
};