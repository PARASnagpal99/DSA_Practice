class Solution {
public:
    
   void dfs(int src , vector<int>&temp ,  vector<vector<int>>&res ,  vector<vector<int>>& graph){
           int n = graph.size() ;
           temp.push_back(src);
           if(src==(n-1)) res.push_back(temp) ;
           for(auto &child : graph[src]){
               dfs(child,temp,res,graph);
           }
       temp.pop_back();
   }
    
    
    
    
    
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res ;
        vector<int> temp ;
        dfs(0,temp,res,graph);
        return res ;
    }
};