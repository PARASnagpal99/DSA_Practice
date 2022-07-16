class Solution {
public:
    vector<pair<int,int>>dirs = {{0,1} , {0,-1} , {1,0} , {-1,0} } ;
    int mod = 1e9 + 7 ;
    int dp[55][55][55] ;
    
    int func(int i , int j , int moves , int n , int m ){
        
        if(i >= n or j >= m or i < 0 or j < 0 ) return 1 ;
        
        if(moves == 0) return 0 ;
        
        if(dp[i][j][moves]!=-1) return dp[i][j][moves] ;
        
        int ans = 0 ;
        
        for(auto &it : dirs){
            ans = (ans + func(i+it.first,j+it.second,moves-1,n,m))%mod ;
        }
        
        return dp[i][j][moves] = ans%mod ;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        int ans = (func(startRow,startColumn,maxMove,m,n)) ;
        return ans ;
    }
};