class Solution {
public:
    unordered_set<int> visited;
    double dfs(int src , vector<int> graph[] , int time , int target ){
          visited.insert(src) ;
        
          if(time == 0){
              if(src == target) return 1.00 ;
              else return 0.00 ;
          }
        
        int cnt = 0 ;
        double ans ;
        double child_ans = 0.00 ;
        for(auto &child : graph[src]){
            
            if(!visited.count(child)){
                cnt++;
                child_ans += dfs(child,graph,time-1,target);
            }
            
        }
        
        if(cnt > 0){
            ans = (1.00/((1.00)*cnt)) ;
            ans = (ans*child_ans) ;
        }else{
            if(src == target){
                return 1.00 ;
            }else{
                return 0.00 ;
            }
        }
        
        return ans ;
    
    }
    

    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> graph[n+1] ;
        
        for(auto &it : edges){
            int u = it[0] , v = it[1] ;
            graph[u].push_back(v) ;
            graph[v].push_back(u) ;
        }
        
        visited.clear() ;
        double ans = dfs(1,graph,t,target) ;
        return ans ;
        
    }
};