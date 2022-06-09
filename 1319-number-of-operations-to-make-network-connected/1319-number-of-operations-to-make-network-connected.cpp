class Solution {
public:
    void dfs(int src , vector<int>graph[] , vector<bool> &vis){
         vis[src] = true ;
         for(auto child : graph[src]){
             if(!vis[child]){
                 dfs(child,graph,vis) ;
             }
         }
    }
    
    int makeConnected(int n, vector<vector<int>>& nums) {
        if(nums.size() < n-1 ) return -1 ;
        vector<int> graph[n] ;
        for(int i=0 ; i<nums.size() ; ++i){
            graph[nums[i][0]].push_back(nums[i][1]);
            graph[nums[i][1]].push_back(nums[i][0]);
        }
        
        int ans = 0 ;
        vector<bool> vis(n,0);
        for(int i=0 ; i<n ; ++i){
            if(!vis[i]){
                dfs(i,graph,vis);
                ans++;
            }
        }
        
        return ans-1 ;
        
    }
};