class Solution {
public:
    #define ll long long 
    
    bool isValid(vector<int>& time , ll mid , ll k){
        ll cnt = 0 ;
        
        for(int i=0 ; i<time.size() ; ++i){
            cnt += (mid / time[i]) ;
        }
        
        return cnt >= k ;
    }
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        sort(time.begin(),time.end());
        
        ll lo = 0 ;
        ll hi = ((ll)totalTrips * time[0]);
        
        ll ans = -1 ;
        
        while(lo <= hi){
            ll mid = lo + (hi-lo)/2 ;
            
            if(isValid(time,mid,totalTrips)){
                ans = mid ;
                hi = mid - 1 ;
            }else{
                lo = mid + 1 ;
            }
        }
        return ans ;
    }
};