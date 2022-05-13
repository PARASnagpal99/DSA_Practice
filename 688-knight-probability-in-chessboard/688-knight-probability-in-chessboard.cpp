class Solution {
public:
//     double func(int n , int k , int r , int c , vector<vector<vector<double>>>&dp){
//         if(dp[r][c][k]) return dp[r][c][k] ;
//         if(r<0 or c<0 or r>=n or c>=n) return 0 ;
//         if(k==0) return 1.00 ;
        
//         double prob = func(n,k-1,r+2,c+1,dp) + func(n,k-1,r+1,c+2,dp) +
//                func(n,k-1,r-2,c-1,dp) + func(n,k-1,r-1,c-2,dp) +
//                func(n,k-1,r-1,c+2,dp) + func(n,k-1,r+2,c-1,dp) + 
//                func(n,k-1,r+1,c-2,dp) + func(n,k-1,r-2,c+1,dp) ;
        
//         double res = prob/8.00 ;
//         dp[r][c][k] = prob ; 
//         return prob ;
//     }
    
double helper(int N, int K, int row, int col, vector<vector<vector<double>>>& memo){

        if(row < 0 || col < 0 || row >= N || col >= N) return 0.0;
        
        if(K == 0) return 1.0;
        
        if(memo[row][col][K] != -1) return memo[row][col][K];
        
        double ans = 
            helper(N, K-1, row+2, col+1, memo) + helper(N, K-1, row+1, col+2, memo) +       
            helper(N, K-1, row-1, col+2, memo) + helper(N, K-1, row-2, col+1, memo) + 
            helper(N, K-1, row-2, col-1, memo) + helper(N, K-1, row-1, col-2, memo) +
            helper(N, K-1, row+1, col-2, memo) + helper(N, K-1, row+2, col-1, memo);
        
        double result  = ans / 8.0;
        memo[row][col][K] = result;
        return result;
    }
    
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double> > > dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return helper(n,k,row,column,dp);
    }
};