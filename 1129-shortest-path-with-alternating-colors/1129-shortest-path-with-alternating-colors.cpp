class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
         vector<vector<pair<int,int>>> graph(n) ;
         
        for(auto &edge : redEdges){
            graph[edge[0]].push_back({edge[1],1}) ;   // 1 denotes red color of the edge arriving to the node 
        }
        
        
        for(auto &edge : blueEdges){
            graph[edge[0]].push_back({edge[1],-1});  // -1 denotes blue color of  the edge arriving to the node 
        }
        
        
        vector<int> red_dist(n,INT_MAX-100) ; // dist if edge arriving on node is red 
        vector<int> blue_dist(n,INT_MAX-100) ;  // dist if edge arriving on node is blue
        
        red_dist[0] = 0 , blue_dist[0] = 0 ;
        queue<int> q ;
        q.push(0) ;
        
        while(!q.empty()){
           int node = q.front() ;
           q.pop() ;
           
           for(auto &[child,color] : graph[node]){
               
               if(color==1 && blue_dist[node] + 1 < red_dist[child]){
                   red_dist[child] = blue_dist[node] + 1 ;
                   q.push(child);
               }
               
               if(color==-1 && red_dist[node] + 1 < blue_dist[child]){
                   blue_dist[child] = red_dist[node] + 1 ;
                   q.push(child) ;
               }
               
           }
            
        }
        
        vector<int> res(n,-1) ;
        for(int i=0 ; i<n ; ++i){
            int dist = min(red_dist[i],blue_dist[i]);
            if(dist!=INT_MAX-100){
                res[i] = dist ;
            }
        }
        
        return res ;
        
    }
};