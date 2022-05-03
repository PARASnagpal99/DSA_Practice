class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int n = arr.size() ;
         vector<int> hsh(n+k+1,0);
         for(int i=0 ; i<n ; ++i){
             if(arr[i]<=n+k){
                 hsh[arr[i]]++;
             }
         }
        int z = 0 ;
        int res ;
        for(int i=1 ; i<=n+k ; ++i){
            if(hsh[i]==0){
                z++;
                if(z==k){
                    res = i ;
                    break ;
                }
            }
        }
        
        return res ;
    }
};