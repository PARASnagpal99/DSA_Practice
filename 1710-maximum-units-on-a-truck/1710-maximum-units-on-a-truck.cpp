class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end() , [&] (const vector<int> a , const vector<int> b){
              return a[1] > b[1] ;
        });
        
        int n = boxTypes.size() ;
        int cnt = 0 ;
        
        
        for(int i=0 ; i<n ; ++i){
            if(truckSize  <= 0){
                break ;
            }
            
            int take = min(truckSize , boxTypes[i][0]);
            
            if(take <= truckSize){
                cnt += (take * boxTypes[i][1]);
                truckSize-=take ;
            }
            
        }
        
        
        return cnt ;
        
        
        
        
        
    }
};