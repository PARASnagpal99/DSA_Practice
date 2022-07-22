class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
       int INF = 1e6 ; 
       vector<vector<int>>dp(n,vector<int>(n,INF));
       
       for(auto &edge : edges){
           dp[edge[0]][edge[1]] = edge[2] ;
           dp[edge[1]][edge[0]] = edge[2] ;
       } 
      
       for(int i=0 ; i<n ; ++i) dp[i][i] = 0 ; 
        
       for(int k=0 ; k < n ; ++k){
         for(int i=0 ; i<n ; ++i){
             for(int j=0 ; j<n ; ++j){
                 if(dp[i][k]!=INF && dp[k][j]!=INF)
                     dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
             }
          }
       }
        
      int min = n ;  
      int ans = -1 ;  
        
      for(int i=0 ; i<n ; ++i){
          int cnt = 0 ;
          for(int j=0 ; j<n ; ++j){
              if(dp[i][j] <= d ){
                  cnt++;
              }
          }
          if(cnt <= min){
              min = cnt ;
              ans = i ;
          }
      }  
      
      return ans ;  
        
        
        
        
    }
};