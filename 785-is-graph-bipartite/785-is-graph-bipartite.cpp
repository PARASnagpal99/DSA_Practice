class Solution {
public:
    bool dfs(int src , vector<bool>&vis , vector<int>&color , vector<vector<int>>& graph){
        
        for(auto &child : graph[src]){
            if(color[src]==color[child]) return false ;
            else if(!vis[child]){
                  vis[child] = true ;
                  color[child] = !color[src] ;
                  if(!dfs(child,vis,color,graph)) return false ;
            }
        }
        
        return true ;
    }
    
    
    
    
    bool isBipartite(vector<vector<int>>& graph) {
           int n = graph.size() ;
           vector<bool> vis(n,false) ;
           vector<int> color(n,-1) ;
           
        for(int i=0 ; i<n ; ++i){ 
            if(!vis[i]){
                color[i] = 0 ;
                vis[i] = true ;
                if(!dfs(i,vis,color,graph)) return false ;
            }
        }
        return true ;
    }
};