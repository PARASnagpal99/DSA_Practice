class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> graph[n] ;
        
        for(auto &it : connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(-it[0]);
        }
        
        vector<bool> vis(n,0);
        queue<int> q ;
        q.push(0) ;
        vis[0] = true ;
        int cnt = 0 ;
        
        while(!q.empty()){
            int par = q.front() ;
            q.pop() ;
            for(auto &child : graph[par]){
                
                if(!vis[abs(child)]){
                    vis[abs(child)] = true ;
                    if(child > 0) cnt++;
                    q.push(abs(child)) ;
                }
                
                
            }
        }
        
        return cnt ;
    }
};