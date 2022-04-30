class Solution {
public:
    int dp[205][205] ;
    int func(int i , int j , vector<vector<int>>&grid){
        int n = grid.size();
        if(i==n-1) return grid[i][j] ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int ans1 = grid[i][j] + func(i+1,j,grid) ;
        int ans2 = grid[i][j] + func(i+1,j+1,grid);
        return dp[i][j] = min(ans1,ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        vector<int>front(n,0),cur(n,0) ;
        for(int i=0 ; i<n ; ++i){
            front[i] = triangle[n-1][i] ;
        }
        for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+front[j];
            int diagonal = triangle[i][j]+front[j+1];
            
            cur[j] = min(down, diagonal);
        }
        front=cur;
      }
    return front[0] ;
    }
};