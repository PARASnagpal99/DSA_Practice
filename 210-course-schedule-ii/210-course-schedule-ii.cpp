class Solution {
private :
public:
	unordered_map<int, vector<int>> adj;
	vector<int> ans;
	int t ;
	vector<int> vis;
	bool dfs(int u)
	{
		vis[u] = -1;  //when we are visiting node u
		for (int v : adj[u])
		{
			if (vis[v] == -1) return false;
			if (vis[v] == 0 && dfs(v) == false) return false;
		}
		vis[u] = 1;  //node u is visited
		ans[--t] = u;
		return true;
	}
    
    
    
	vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
		for (auto e : prerequisites)
			adj[e[1]].push_back(e[0]); //u->v
		ans = vector<int>(numCourses, 0);
		t = numCourses;
		vis = vector<int>(numCourses, false);
		for (int u = 0; u < numCourses; u++)
		{
			if (vis[u] == 0)
				if (dfs(u) == false) return{}; //has cycle
		}
		return ans;
	}

};