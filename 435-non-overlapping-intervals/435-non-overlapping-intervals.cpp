class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size() ;
        sort(arr.begin(),arr.end());
        int prev = arr[0][1] ;
        int cnt = 0 ;
        for(int i=1 ; i<n ; ++i){
            if(arr[i][0]>=prev){
                prev = arr[i][1] ;
            }else{
                cnt++;
                prev = min(prev,arr[i][1]);
            }
        }
        return cnt ;
    }
};