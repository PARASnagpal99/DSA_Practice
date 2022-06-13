class Solution {
public:
    int dfs(int src ,  vector<int> graph[] , vector<int>& time ){
        int ans = 0 ;
        for(auto &child : graph[src]){
            ans = max(ans , dfs(child , graph, time));
        }
        
        return ans + time[src] ;
    }
    
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> graph[n+1] ;

        for(int i=0 ; i<n ; ++i){
            if(manager[i]==-1) continue ;
            graph[manager[i]].push_back(i);
        }
        
        
        int ans = 0 ;
        ans+=dfs(headID,graph,informTime);
        return ans ;
    }
};