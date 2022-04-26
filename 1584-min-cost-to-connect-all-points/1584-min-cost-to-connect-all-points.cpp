class Solution {
public:
 static const int N = 1e3 + 5 ;
    int parent[N];
    int size[N] ;
    void make(int v){
        parent[v] = v ;
        size[v] = 1 ;
    }
    
    int find(int v){
         if(v==parent[v]) return v ;
         return find(parent[v]);
    }
    
    void Union(int a , int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b] = a ;
            size[a]+=size[b];
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
           int n = points.size()  ;
           vector<pair<int,pair<int,int>>>edges ;
           for(int i=0 ; i<n ; ++i){
               for(int j=i+1 ; j<n ; ++j){
                   int wt = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                   edges.push_back({wt,{i,j}});
               }
           }
        sort(edges.begin(),edges.end());
        int total_cost = 0 ;
        for(int i=1 ; i<=n ; ++i) make(i) ;
        for(auto &edge : edges){
            int wt = edge.first ;
            int u = edge.second.first ;
            int v = edge.second.second ;
            if(find(u)==find(v)) continue ;
            Union(u,v);
            total_cost+=wt;
        }
        return total_cost ;
    }
};