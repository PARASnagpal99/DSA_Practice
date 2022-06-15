class Solution {
public:
//     vector<int> graph[2005] ;
//     vector<int> vis(2005,0);
//     vector<int> color(2005,-1) ;
    
    
//     bool dfs(int src){
//         for(auto &child : graph[src]){
//             if(color[child]==color[src]) return false ;
//             else if(!vis[child]){
//                 vis[child] = true ;
//                 color[child] = !color[src] ;
//                 if(!dfs(child)) return false ;
//             }
//         }
//         return true ;
//     }
    
    
        bool dfs(int src , vector<bool>&vis , vector<int>&color , vector<int> graph[]){
        
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
    
    
    
    


    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n+1];
        for(auto &it : dislikes){
            graph[it[1]].push_back(it[0]);
            graph[it[0]].push_back(it[1]);
        }
        vector<bool> vis(n+1,false) ;
        vector<int> color(n+1,-1) ; 
        
        
        for(int i=1 ; i<=n ; ++i){ 
            if(!vis[i]){
                color[i] = 0 ;
                vis[i] = true ;
                if(!dfs(i,vis,color,graph)) return false ;
            }
        }
        return true ;
    }
};