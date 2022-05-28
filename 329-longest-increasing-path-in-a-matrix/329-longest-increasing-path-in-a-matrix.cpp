class Solution {
public :
   int dfs(int x , int y , vector<vector<int>>& matrix , vector<vector<int>>& dp){
       int n = matrix.size() , m = matrix[0].size() ;
       if(dp[x][y]) return dp[x][y] ;
       vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
       int ans = 1 ;
       for(int i=0 ; i<4 ; ++i){
           int X = x + dir[i][0] ;
           int Y = y + dir[i][1] ;
           
           if(X<0 or Y<0 or X>=n or Y>=m ) continue ;
           if(matrix[X][Y]<=matrix[x][y]) continue ;
           ans = max(ans,1+dfs(X,Y,matrix,dp));
       }
       return dp[x][y] = ans ;
   }
   
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         int n = matrix.size() , m = matrix[0].size() ;
         if(n==0) return 0 ;
         vector<vector<int>>dp(n,vector<int>(m,0));
            int res = 0 ;
            for(int i=0 ; i<n ; ++i){
                for(int j=0 ; j<m ; ++j){
                    if(!dp[i][j]) res = max(res,dfs(i,j,matrix,dp));
                }
            }
            
        return res ;
    }
};