class Solution {
public:
    bool isValid(vector<int>&dist , int speed , double hour){
        int n = dist.size() ;
        double time = 0 ;
        for(int i=0 ; i<n ; ++i){
            if(time > hour) return false ;
            if(i!=n-1){
                time += ((dist[i]+speed-1)/speed) ;
            }else{
                time += double(dist[i])/speed ;
            }
        }
        
        return time<=hour ;
    }
    
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size() ;
        if(n-1 >= hour) return -1 ;
        int lo = 1 , hi = 1e7 ;
        int ans = hi ;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            if(isValid(dist,mid,hour)){
                ans = mid ;
                hi = mid-1 ;
            }else{
                lo = mid+1 ;
            }
        }
        
        return ans ;
    }
};