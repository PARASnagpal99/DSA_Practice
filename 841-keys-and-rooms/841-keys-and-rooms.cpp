class Solution {
public:
    void dfs(int src , vector<vector<int>>& graph , vector<bool> &vis){
        vis[src] = true ;
        for(auto child : graph[src]){
            if(!vis[child]){
                vis[child] = true ;
                dfs(child,graph,vis);
            }
            
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<bool> vis(n,false);
        
        dfs(0,graph,vis);
        
        for(int i=0 ; i<n ; ++i){
            if(!vis[i]) return false ;
        }
        
        return true ;
        
        
        
        
    }
};