class Solution {
public:
    double func(int N , int K , int r , int c , vector<vector<vector<double>>>& dp){
        if(r<0 or c<0 or r>=N or c>=N) return 0 ;
        if(K==0) return 1.00 ;
        
        if(dp[r][c][K]) return dp[r][c][K] ;
        double prob = 
            func(N, K-1, r+2, c+1, dp) + func(N, K-1, r+1, c+2, dp) +       
            func(N, K-1, r-1, c+2, dp) + func(N, K-1, r-2, c+1, dp) + 
            func(N, K-1, r-2, c-1, dp) + func(N, K-1, r-1, c-2, dp) +
            func(N, K-1, r+1, c-2, dp) + func(N, K-1, r+2, c-1, dp);
        
        double res = prob/8.0 ;
        dp[r][c][K] = res ; 
        return res ;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double> > > dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1)));
        return func(n,k,row,column,dp);
    }
};