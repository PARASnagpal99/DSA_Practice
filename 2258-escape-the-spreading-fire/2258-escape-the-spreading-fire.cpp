class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0} , {-1,0} , {0,1} , {0,-1} } ;
        
    
    bool isValid(int i , int j , int time , vector<vector<int>> &visited , vector<vector<int>> &fire ){
        
        int n = fire.size() , m = fire[0].size() ;
        
        if(i == n-1 && j == m-1) return true ;
        
        if(fire[i][j] <= time) return false ;
        
        visited[i][j] = time ;
        
        for(auto &it : dirs){
            int nx = i + it.first ;
            int ny = j + it.second ;
            
            if(nx >= 0 && ny >=0 && nx < n && ny < m && visited[nx][ny] > time + 1 && fire[nx][ny] >= time + 1  && isValid(nx,ny,time+1,visited,fire)){
                return true ;
            }
        }
        
        return false ;
    }
    
    
    
    
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        
        vector<vector<int>>fire(n,vector<int>(m,INT_MAX)) ;
        
        queue<array<int,3>>q ;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<m ; ++j){
                if(grid[i][j] == 1){
                    
                    fire[i][j] = 0 ;
                    q.push({i,j,0});
                    
                }else if(grid[i][j] == 2){
                    fire[i][j] = -1 ;
                }
            }
        }
        
        
        while(!q.empty()){
            
            auto [i , j , dist] = q.front() ;
            q.pop() ;
            
            for(auto &it : dirs){
                int nx = i + it.first ;
                int ny = j + it.second ;
                
                if(nx >=0 && nx < n && ny >= 0 && ny < m && grid[nx][ny]!=2 && fire[nx][ny] > dist + 1){
                    fire[nx][ny] = dist + 1 ;
                    q.push({nx,ny,dist+1});
                }   
            }   
        }
        
        
        
        int lo = 0 , hi = n*m + 1 ;
        
        
        vector<vector<int>> visited(n,vector<int>(m));
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            
            for(auto &it : visited){
                fill(it.begin(),it.end(),INT_MAX) ;
            }
           
            if(isValid(0,0,mid,visited,fire)){
                lo = mid+1 ;
            }else{
                hi = mid-1 ;
            }
        }
        
        return hi == n*m + 1 ? 1e9 : hi ;
    }
};