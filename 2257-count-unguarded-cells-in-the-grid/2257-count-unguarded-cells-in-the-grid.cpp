class Solution {
public:
    #define ll long long 
    void dfs(vector<vector<int>>& grid , int x , int y , int dir){
        int m = grid.size() , n = grid[0].size() ;
        if(x<0 or y<0 or x>=m or y>=n) return ;
        if(grid[x][y]==2 or grid[x][y]==1) return ;
        grid[x][y]=3;
        if(dir==1){
            dfs(grid,x+1,y,dir);
        }else if(dir==2){
            dfs(grid,x,y+1,dir);
        }else if(dir==3){
            dfs(grid,x-1,y,3);
        }else{
            dfs(grid,x,y-1,4);
        }
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       vector<vector<int>>grid(m,vector<int>(n,0));
        
       for(int i=0 ; i<guards.size() ; ++i){
               int x = guards[i][0];
               int y = guards[i][1];
               grid[x][y] = 1 ;
           }
           
        for(int i=0 ; i<walls.size() ; ++i){
            int x = walls[i][0];
            int y = walls[i][1];
            grid[x][y] = 2 ;
        }
        
          for(int i=0;i<guards.size();i++){
            int x=guards[i][0];
            int y=guards[i][1];
              dfs(grid,x+1,y,1);
              dfs(grid,x,y+1,2);
              dfs(grid,x-1,y,3);
              dfs(grid,x,y-1,4);
          }
        ll ans = 0 ;
        for(int i=0 ; i<m ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(!grid[i][j])ans++;
            }
        }
        return ans ;
    }
};