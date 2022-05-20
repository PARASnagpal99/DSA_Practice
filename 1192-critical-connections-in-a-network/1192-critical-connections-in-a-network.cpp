class Solution {
public:
    vector<vector<int>>ans ;
    void dfs(int node , int parent , vector<int> &vis , vector<int> &tin , vector<int> &low , int &timer , vector<int> graph[]){
            vis[node] = 1 ;
            tin[node] = low[node] = timer++;
            for(auto &it : graph[node]){
                if(it==parent) continue ;
                
                if(!vis[it]){
                    dfs(it,node,vis,tin,low,timer,graph);
                    low[node] = min(low[node],low[it]);
                    if(low[it]>tin[node]){
                        ans.push_back({node,it});
                    }
                }else{
                    low[node] = min(low[node],tin[it]);
                }
            }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<int> graph[n] ;
            for(int i=0 ; i<connections.size() ; ++i){
                     int u = connections[i][0] ;
                     int v = connections[i][1] ;
                graph[u].push_back(v);
                graph[v].push_back(u) ;
            }
        
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        int timer = 0 ;
        for(int i=0 ; i<n ; ++i){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,timer,graph);
            }
        }
       return ans ;   
    }
};