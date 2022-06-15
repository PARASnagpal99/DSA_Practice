class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> graph[n] ;
        set<pair<int,int>>st ;
        for(auto &it : roads){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            st.insert({it[0],it[1]});
            st.insert({it[1],it[0]});
        }
        int ans = 0 ;
        for(int i=0 ; i<n ; ++i){
            for(int j=i+1 ; j<n ; ++j){
                int u = graph[i].size() , v = graph[j].size() ;
                int cnt = u + v ;
                if(st.count({i,j})) cnt--;
                
                ans = max(cnt , ans);
                
            }
        }
        
        
        return ans ;
        
        
        
    }
};