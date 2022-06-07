class Solution {
public:
    
    bool isValid(vector<int> pos , int ps , int m){
        int cnt = 1 ;
        int prev = pos[0] ;
        for(auto it = 1 ; it < pos.size() ; it++){
            
            if(pos[it] - prev  >= ps){
                prev = pos[it] ;
                cnt++;
                if(cnt>=m) return true ;
            }
        }
        return cnt >= m ;
    }
    
    
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size() ;
        sort(pos.begin(),pos.end());
        int lo = 1 , hi = pos[n-1] - pos[0] ;
        int ans = 0 ;
        while(lo<=hi){
            int mid  = lo + (hi-lo)/2 ;
            if(isValid(pos,mid,m)){
                ans = max(ans,mid);
                lo = mid+1 ;
            }else{
                hi = mid-1 ;
            }
        }
        
        return ans ;
    }
};