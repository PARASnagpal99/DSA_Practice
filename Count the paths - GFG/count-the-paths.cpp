// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
void dfs(int start , int end , vector<int> graph[] , vector<int> &vis , int &ans){
     if(start==end){
         ans++;
         return ;
     }
     
     if(vis[start]) return ; 
     
     vis[start] = true ;
     
     for(auto &child : graph[start]){
         if(!vis[child]){
             dfs(child,end,graph,vis,ans);
         }
     }
     
     vis[start] = false ;
}



	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	        vector<int> vis(n,0) ;
	        vector<int> graph[n] ;
	        for(auto &it : edges){
	            graph[it[0]].push_back(it[1]);
	        }
	        int ans = 0 ;
	        dfs(s,d,graph,vis,ans);
	        
	        return ans ;
	        
	        
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends