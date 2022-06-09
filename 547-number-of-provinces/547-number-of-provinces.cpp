class Solution {
public:
    void dfs(int src , vector<int> graph[] , vector<bool>&vis){
        vis[src] = true ;
        for(auto child : graph[src]){
            if(!vis[child]){
                dfs(child,graph,vis) ;
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size() ;
        vector<bool> vis(n,0);
        vector<int> graph[n] ;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
                if(nums[i][j]){
                    graph[i].push_back(j) ;
                }
            }
        }
        
        int cnt = 0 ;
        for(int i=0 ; i<n ; ++i){
                if(!vis[i]){
                    dfs(i,graph,vis);
                    cnt++;
                }
        }
        
        return cnt ;
        
    }
};