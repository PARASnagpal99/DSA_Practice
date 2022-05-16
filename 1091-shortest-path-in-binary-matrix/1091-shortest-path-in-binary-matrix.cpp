class Solution {
public:
    bool isValid(int x , int y , vector<vector<int>>& grid){
        int n = grid.size() , m = grid[0].size() ;
        return (x>=0 && y>=0 && y<m && x<n && grid[x][y]==0) ;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
           int n = grid.size() , m = grid[0].size() ;
           if(grid[0][0]==1 or grid[n-1][m-1]==1) return -1 ;
           vector<pair<int,int>>directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1, -1},{-1, 1}};
           queue<pair<int,int>>q ;
           q.push({0,0});
           grid[0][0] = 1 ;
           while(!q.empty()){
               auto curr = q.front() ;
               q.pop() ;
               int x = curr.first , y = curr.second ;
               if(x==n-1 && y==m-1) return grid[x][y] ;
               for(auto dir : directions){
                   int x1 = x + dir.first ;
                   int y1 = y + dir.second ;
                   if(isValid(x1,y1,grid)){
                       q.push({x1,y1});
                       grid[x1][y1] = grid[x][y] + 1 ;
                   }
               }
           }
        return -1 ;
    }
};