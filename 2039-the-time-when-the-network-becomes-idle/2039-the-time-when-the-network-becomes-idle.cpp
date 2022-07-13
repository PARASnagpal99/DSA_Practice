class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size() ;
        vector<int> graph[n] ;
        vector<int> dist(n,0) ;
        
        for(auto &it : edges){
            graph[it[0]].push_back(it[1]) ;
            graph[it[1]].push_back(it[0]) ;
        }
        
        
        queue<int> q ;
        q.push(0) ;
        vector<bool> vis(n,false) ;
        vis[0] = true ;
        
        while(!q.empty()){
            auto curr = q.front() ;
            q.pop() ;
            for(auto child : graph[curr]){
                if(!vis[child]){
                    q.push(child) ;
                    vis[child] = true ;
                    dist[child] = dist[curr] + 1 ;
                }
            }
        }
        
        int mx_time = 0 ;
        
        for(int i=1 ; i<n ; ++i){
            
           int time_for_ExtraSignals = 2*dist[i] - 1 ;
            
           int number_of_ExtraSignals = time_for_ExtraSignals/(patience[i]) ;
           
            // timeTaken to send last signal + time taken to get back to  sender .
           int last_signalTimeTaken = (number_of_ExtraSignals) * patience[i] + 2*dist[i] ;
            
           mx_time = max(mx_time,last_signalTimeTaken + 1 ) ; // + 1 for becoming idle .
            
        }
        
        return mx_time ;
        
        
        
        
        
    }
};