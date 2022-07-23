class Solution {
public:
  vector<vector<int>> graph ;
  vector<int> count ;
  vector<int> res ;
    
    
  void dfs(int node , int par){
      for(auto &child : graph[node]){
          if(child != par){
              dfs(child,node);
              count[node] += count[child] ;
              res[node] += (res[child] + count[child]) ;
          }
      }
     count[node]+=1;
  }
  
    
  void dfs2(int node , int par , int n){
      for(auto &child : graph[node]){
          if(child != par){     
              res[child] = (res[node] - count[child] + n - count[child]) ;
              dfs2(child,node,n) ;
          }
      }
  }  
    
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n) ;
        count.resize(n);
        res.resize(n) ;
        
        for(auto &it : edges){
           graph[it[0]].push_back(it[1]);
           graph[it[1]].push_back(it[0]);
        }
        
        dfs(0,-1) ;
        dfs2(0,-1,n) ;
        
        return res ;
        
    }
};