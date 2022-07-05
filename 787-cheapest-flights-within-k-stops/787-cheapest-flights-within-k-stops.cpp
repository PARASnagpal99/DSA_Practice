class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         int INF = 1e8 ;
         vector<int> dist(n , INF) ;
         dist[src] = 0 ;
        
        for(int i=1 ; i<=k+1 ; ++i){
            vector<int> temp(dist) ;
            for(auto &it : flights){
                temp[it[1]] = min(temp[it[1]] , dist[it[0]] + it[2] ) ;
            }
            dist = temp ; 
            
        }
        
        if(dist[dst] == 1e8) return -1 ;
        
        return dist[dst] ;
    }
};