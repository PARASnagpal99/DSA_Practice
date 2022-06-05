class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       int ans = 0 ;
       queue<pair<int,int>> q ;
       
       for(int i=0 ; i<grid.size() ; ++i){
           for(int j=0 ; j<grid[i].size() ; ++j){
               if(grid[i][j]) q.push({i,j});
           }
       }
        
        // multisource BFS
       vector<pair<int,int>> dirs = {{0,1} , {-1,0} , {0,-1} , {1,0} } ;
       while(!q.empty()){
           auto curr = q.front() ;
           q.pop() ;
           
           for(auto &it : dirs){
               int newX = curr.first + it.first ;
               int newY = curr.second + it.second ;
               if(newX>=0 && newY>=0 && newX<grid.size()  && newY < grid[0].size() && grid[newX][newY]==0){
                   q.push({newX,newY});
                   grid[newX][newY] = grid[curr.first][curr.second] + 1 ;
                   ans = max(grid[newX][newY],ans);
               }
           }   
       } 
       if(ans>0) return ans-1 ; 
       return -1 ; 
    }
};