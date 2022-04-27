class Solution {
public:
    static const int N = 1e5 + 7 ;
    vector<int> g[N] ;
    bool visited[N] ;
    void dfs(string &s , int vertex , vector<char>& characters , vector<int>& indices){
        characters.push_back(s[vertex]);
        indices.push_back(vertex);
        visited[vertex] = true ;
        
        for(auto child : g[vertex]){
             if(!visited[child]){
                 dfs(s,child,characters,indices);
             }
        }
    }
    
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto &it : pairs){
            int x = it[0] ;
            int y = it[1] ;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        for(int vertex=0 ; vertex<s.length() ; ++vertex){
            if(!visited[vertex]){
                vector<char> characters ;
                vector<int> indices ;
                dfs(s,vertex,characters,indices);
                sort(characters.begin(),characters.end());
                sort(indices.begin(),indices.end());
                for(int i=0 ; i<characters.size() ; ++i){
                    s[indices[i]] = characters[i] ;
                }
            }
        }
        
        return s ;
    }
};