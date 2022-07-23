class Solution {
public:
    int parent[65]   ;
    
    void make(int v , int par){
         parent[v] = par ;
    }
    
    int find(int v){
         if(v == parent[v]) return v ;
        
         return parent[v] = find(parent[v]) ;
    }
    
    bool isNotUnion(int a , int b){
        int pa = find(a) ;
        int pb = find(b) ;
        
        if(pa == pb) return false ;
        
        parent[pb] = pa ;
        return true ;
    }
    
    
    
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() ;
        if(n == 0) return 0 ;
        
        for(int i=0 ; i<n ; i+=2){
            make(row[i],row[i]);
            make(row[i+1],row[i]) ;
        }
        
        
        int ans = 0 ;
        
        for(int i=0 ; i<n ; i+=2){
            if(isNotUnion(i,i+1)){
                ans++;
            }
        }
        
        return ans ;
        
        
        
        
        
    }
};