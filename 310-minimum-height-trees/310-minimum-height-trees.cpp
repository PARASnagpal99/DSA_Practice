class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
          if(n < 2){
              vector<int> ans ;
              for(int i=0 ; i<n ; ++i) ans.push_back(i) ;
              return ans ;
          }   
        
          vector<int> graph[n] ;
          vector<int> degree(n,0) ;
        
        
          for(auto &it : edges){
              graph[it[1]].push_back(it[0]);
              graph[it[0]].push_back(it[1]);
              degree[it[0]]++;
              degree[it[1]]++;
          } 
        
        queue<int> q ;
        
        for(int i=0 ; i<n ; ++i){
            if(degree[i]==1) q.push(i) ;
        }
        
        while(n > 2){
            int sz = q.size() ;
            
            for(int i=0 ; i<sz ; ++i){
                n--;
                int curr = q.front() ;
                q.pop() ;
                
                for(auto &child : graph[curr]){
                    degree[child]--;
                    if(degree[child] == 1) q.push(child) ;
                }

            }
        }
        
        vector<int> res ;
        
        while(!q.empty()){
            int node = q.front() ;
            res.push_back(node);
            q.pop() ;
        }
        
        return res;
        
    }
};