class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int cap) {
        int n = buses.size() , m = passengers.size() ;
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        
        int indx = 0 ;
        int cnt = 0 ;
        int i = 0 ;
        
        while(indx < n-1 && i < m){
            
           if(passengers[i] <= buses[indx] && cnt < cap && indx < n-1){
               i++ ;
               cnt++;
           }else if((passengers[i] > buses[indx] or cnt >= cap) && indx < n-1){
               indx++;
               cnt = 0 ;
           }
             
        }
        
        cnt = cap ;
        while(i < m && passengers[i] <= buses.back() && cnt){
            i++;
            cnt--;
        }
        
        
        int last = cnt ? buses.back() : passengers[i - 1];
        
        
        for(i=i-1 ; i>=0 && last == passengers[i] ; i--){
            last = passengers[i] - 1 ;
        }
        
        return last ;
        
        
        
        
        
    }
};