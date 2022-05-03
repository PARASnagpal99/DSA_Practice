class Solution {
public:
    void dfs(vector<vector<int>>& grid , set<pair<int,int>>&s ,  int i , int j){
        int n = grid.size() ;
        if(i<0 or j<0 or i>=n or j>=n or grid[i][j]!=1) return ;
        s.insert({i,j});
        grid[i][j] = 2 ;
        dfs(grid,s,i+1,j);
        dfs(grid,s,i-1,j);
        dfs(grid,s,i,j+1);
        dfs(grid,s,i,j-1);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size() ;
        bool flag = false ;
        set<pair<int,int>>arr1 , arr2 ;
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(!flag && grid[i][j]==1){
                    dfs(grid,arr1,i,j);
                    flag = true ;
                }else if(flag && grid[i][j]==1){
                    dfs(grid,arr2,i,j);
                }
            }
        }
        
        int res = INT_MAX ;
        for(auto &it1 : arr1){
            for(auto &it2 : arr2){
                res = min(res, abs(it1.first-it2.first) + abs(it1.second-it2.second)-1);
            }
        }
        
        return res ;
        
    }
};