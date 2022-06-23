class Solution {
public:
    
    bool dfs(int src , vector<int>& vis , vector<int> graph[] , int parent ){
        
        vis[src] = true ;
         
        for(auto &child  : graph[src]){
           
            if(!vis[child]){
                if(dfs(child,vis,graph,src)) return true ;
            }else if(child != parent){
                return true ;
            }
        }
        
        return false ;
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        
        vector<int> graph[n+1] ;
        
        vector<int> vis(n+1,0) ;
        vector<int> temp(n+1,0) ;
        for(auto &it : edges){            
            vis = temp ;
            
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            
            if(dfs(it[0] , vis , graph , -1)) return it ;
               
        }
        
        
        return {} ;
        
        
        
    }
};