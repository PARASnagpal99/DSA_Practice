class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>> q ;
        q.push({e[0],e[1]});
        
        int moves = 1 ;
        int n = maze.size() , m = maze[0].size() ;
        vector<pair<int,int>> dirs = {{0,1} , {0,-1} , {-1,0} , {1,0} } ;
        maze[e[0]][e[1]] = '+' ;
        while(!q.empty()){
            int sz = q.size() ;
            
            for(auto i=0 ; i<sz ; ++i){
                auto curr = q.front() ;
                q.pop() ;
                for(auto &it : dirs){
                    auto x = curr.first + it.first ;
                    auto y = curr.second + it.second ;
                    
                    if(x<0 or y<0 or x>=n or y>=m or maze[x][y]=='+') continue ;
                    if(x==0 or y==0 or x==n-1 or y==m-1) return moves ;
                    
                    maze[x][y] = '+' ;
                    q.push({x,y}) ;
                }
            }
            moves++;
        }
        return -1 ;
    }
};