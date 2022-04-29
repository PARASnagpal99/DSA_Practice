class Solution {
public:
    bool bfs(vector<vector<int>>& graph ,vector<int>&visited, int s){
        queue<int>q ;
        visited[s] = 1 ;
        q.push(s);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto child : graph[curr]){
                if(!visited[child]){
                    visited[child] = -1*visited[curr] ;
                    q.push(child);
                }else if(visited[child]==visited[curr]){
                    return false ;
                }
            }
        }
        return true ;
    }
    
    bool dfs(vector<vector<int>>& graph ,vector<int>&visited, int s , int colr){
        visited[s] = colr ;
        for(auto child : graph[s]){
            if(!visited[child]){
                if(dfs(graph ,visited, child , -1*visited[s])==false) return false;
            }else if(visited[child]==visited[s]){
                return false ;
            }
        }
        return true ;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
           int n = graph.size();
           vector<int>visited(n,0);
             for(int i=0 ; i<n ; ++i){
                 if(!visited[i]){
                     if(dfs(graph,visited,i,1)==false) return false;
                 }
             }
        return true ;
    }
};