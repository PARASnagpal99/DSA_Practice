class Solution {
public:
static const int N = 1e5 + 7 ;
    int parent[N] ;
    int size[N] ;
    
    void make(int v){
        parent[v] = v ;
        size[v] = 1 ;
    }
    
    int find(int v){
        if(v==parent[v]) return v ;
        return parent[v] = find(parent[v]) ;
    }
    
    void Union(int a , int b){
        a = find(a) ;
        b = find(b) ;
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b] = a ;
            size[a]+=size[b] ;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length() ;
        
        if(pairs.size()==0) return s ;
        
        for(int i=1 ; i<=n ; ++i){
              make(i) ;
        }
    
        for(auto &it : pairs){
            Union(it[0],it[1]);
        }
        
        map<int,vector<int>>mp ;
        for(int i=0 ; i<n ; ++i){
            mp[find(i)].push_back(i) ;
        }
        
        for(auto &it : mp){
            string st = "" ;
            for(auto &t : it.second){
                st+=s[t] ;
            }
            
            sort(st.begin(),st.end());
            for(int i=0 ; i<it.second.size() ; ++i){
                s[it.second[i]] = st[i] ;
            }
        }
        return s ;
        
        
    }
};