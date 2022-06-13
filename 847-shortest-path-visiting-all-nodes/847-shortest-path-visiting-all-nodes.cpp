class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size() ;
        if(n==1) return 0 ;
        
        int mask_final = ( 1 << n) - 1 ;  // 1 1 1 1 form  , set bit means that node has been visited 
        
        int res = 0 ;
        queue<vector<int>>q ;
        
        vector<vector<int>>visited(n,vector<int>(mask_final));
        
        for(int i=0 ; i<n ; ++i) q.push({i , 1 << i});
        
        while(!q.empty()){
            ++res ;
            int sz = q.size() ;
            for(int i=0 ; i<sz ; ++i){
                int node_id = q.front()[0];
                int visited_bit = q.front()[1] ;
                q.pop();
                for(auto &it : graph[node_id]){
                    int new_visitedBit = visited_bit | (1 << it) ;
                    if(new_visitedBit==mask_final) return res ;
                    if(visited[it][new_visitedBit]==1) continue ;
                    visited[it][new_visitedBit] = 1 ;
                    q.push({it,new_visitedBit});
                    
                }
            }
        }
        
        return -1 ;
    }
};