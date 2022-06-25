class Solution {
public:
    
    bool Cycle(int node , vector<int> graph[] , vector<int> &vis , vector<int> &dfsVis){
         vis[node] = 1 ;
         dfsVis[node] = 1 ;
        
        for(auto &child : graph[node]){
            if(!vis[child]){
                if(Cycle(child,graph,vis,dfsVis)) return true ;
            }else if(dfsVis[child] && vis[child]){
                return true ;
            }
        }
        
        dfsVis[node] = 0 ;
        return false ;
    }
    
    
    void dfs(int node , vector<bool> &vis , stack<int> &st , vector<int> graph[]){
      
      vis[node] = true ;
      
      for(auto &child : graph[node]){
          if(!vis[child]){
              dfs(child,vis,st,graph);
          }
      }
      st.push(node);
  }
    
    
    
    
    

    
    vector<int> findOrder(int n , vector<vector<int>>& nums) {
            
        vector<int> graph[n] ;
        
        for(auto &it : nums){
            graph[it[1]].push_back(it[0]) ;
        }
        
        
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        
        bool flag = 0 ;
        
        for(int i=0 ; i<n ; ++i){
            if(!vis[i]){
                if(Cycle(i,graph,vis,dfsVis)){
                    flag  = true ;
                    break ;
                }
            }
        }
        
        if(flag) return {} ;
        
        vector<bool> vis2(n,0) ;
        stack<int> st ;
        
        for(int i=0 ; i<n ; ++i){
            if(!vis2[i]){
                dfs(i,vis2,st,graph);
            }
        }
        
        vector<int> res ;
        
        while(!st.empty()){
            int x = st.top() ;
            res.push_back(x);
            st.pop() ;
        }
        
        return res ;
    }
};