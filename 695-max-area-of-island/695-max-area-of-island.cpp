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
        int m = grid.size() , n = grid[0].size() ;
        
        
        vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    stack<pair<int,int>> s;
                    s.push({i,j});
                    int count=0;
                    while(!s.empty()){
                        int x=s.top().first,y=s.top().second;
                        s.pop();
                        
                        if(grid[x][y]==0) continue;
                            
                        count++;
                        grid[x][y]=0;
                        
                        for(int k=0;k<4;k++){
                            int x1=x+dirs[k].first,y1=y+dirs[k].second;
                            if(x1>=0 && x1<m && y1>=0 && y1<n && grid[x1][y1]==1){
                                s.push({x1,y1});
                            }
                        }
                    }
                    ans=max(ans,count);
                }
            }
        }
        return ans;
        
    }
};