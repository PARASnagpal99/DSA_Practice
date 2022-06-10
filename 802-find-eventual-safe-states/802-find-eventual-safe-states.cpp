class Solution {
public:
    unordered_set<int> cycles ;
    unordered_set<int> safe ;
    
    bool dfs(vector<vector<int>>& graph , int src , unordered_set<int> &visited){
        
        if(cycles.find(src)!=cycles.end()) return false ;
        
        if(safe.find(src)!=safe.end()) return true ;
        
        if(visited.find(src)!=visited.end()){
            cycles.insert(src);
            return false ;
        }
        
        visited.insert(src);
        
        for(auto &child : graph[src]){
            if(!(dfs(graph,child,visited))){
                cycles.insert(child);
                return false ;
            }
        }
        
        safe.insert(src);
        return true ;
    }
    
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int n = graph.size() ;
         vector<int> res ;
         unordered_set<int> visited ;
         for(int i=0 ; i<n ; ++i){
             
                  if(dfs(graph,i,visited)) res.push_back(i);
             
         }
         
        return res ;
    }
};