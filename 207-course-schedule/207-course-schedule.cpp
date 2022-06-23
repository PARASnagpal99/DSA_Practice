class Solution {
public:
    bool dfs(int src , vector<int> graph[] , vector<int> &vis ){
        
        if(vis[src]==1) return false ;
        
        if(!vis[src]){
            vis[src] = 1 ;
            for(auto &child : graph[src]){
                  if(dfs(child,graph,vis)==false) return false ;
            }
        }
        
        vis[src] = 2 ;
        return true ;
    }
    
    
    bool canFinish(int n , vector<vector<int>>& pre) {
        
        vector<int> graph[n] ;
        vector<int> vis(n,0) ;
        
        for(int i=0 ; i<pre.size() ; ++i){
            graph[pre[i][0]].push_back(pre[i][1]);
        }
        
        for(int i=0 ; i<n ; ++i){
            if(!vis[i]){
                if(dfs(i,graph,vis)==false) return false ;
            }
        }
        
        return true ;
    }
};