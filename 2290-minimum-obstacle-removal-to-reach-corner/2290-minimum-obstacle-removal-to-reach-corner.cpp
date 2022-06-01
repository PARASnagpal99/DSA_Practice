class Solution {
public:
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define ll long long
#define INF 1000000000
#define prDouble(x) cout << fixed << setprecision(10) << x  
#define endl '\n'
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        vector<vector<ll>>dist(n+1,vector<ll>(m+1,1e9)) ;
        queue<pair<int,int>>q ;
        dist[0][0] = grid[0][0] ;
        q.push({0,0}) ;
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}} ;
        while(!q.empty()){
            ll x = q.front().first ;
            ll y = q.front().second ;
            q.pop() ;
            for(auto &it : dir){
                ll newX = x + it.first ;
                ll newY = y + it.second ;
                if(newX>=0 && newX<n && newY>=0 && newY<m && (dist[x][y] + grid[newX][newY] < dist[newX][newY])){
                    dist[newX][newY] = dist[x][y] + grid[newX][newY] ;
                    q.push({newX,newY}) ;
                }
            }
        }
        
        return dist[n-1][m-1] ;
     }
};