class Solution {
private:
    double dfs(unordered_map<string, vector<pair<string, double>>> &graph, unordered_set<string> visited, string start, string end){
        if(graph.count(start)==0 or graph.count(end)==0){
            return -1.00 ;
        }
        
        if(start==end) return 1.00 ;
        visited.insert(start);
        for(auto &child : graph[start]){
            if(visited.count(child.first)==0){
				double res = dfs(graph, visited, child.first, end);
				if(res != -1.0){
					return res*child.second;
				}
			}
		}
		return -1.0;
    }
    
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       unordered_map<string , vector<pair<string,double>>> graph ;
       for(int i=0 ; i<equations.size() ; ++i){
           graph[equations[i][0]].push_back({equations[i][1],values[i]});
           graph[equations[i][1]].push_back({equations[i][0],1.00/values[i]});
       }
        
       vector<double>ans ; 
       for(auto &it : queries){
           unordered_set<string> visited ;
           double res = dfs(graph,visited,it[0],it[1]);
           ans.push_back(res);
       }
       return ans ; 
        
    }
};