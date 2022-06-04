class Solution {
public:
    /*
    3 cases 
    if x <= min 
    if x >= max 
    if  min < x < max
    for first 2 we can easily find out by just iterating 
    for third case we can find lower bound  and then using two pointers 
    
    */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
          int n = arr.size() ;
          vector<int> res ;
          if(x<=arr[0]){
              for(int i=0 ; i<k ; ++i) res.push_back(arr[i]) ;
          }else if(x>=arr.back()){
              for(int i=n-1 ; i>=n-k ; --i) res.push_back(arr[i]) ;
              reverse(res.begin(),res.end());
          }else{
              
              int pos = lower_bound(arr.begin(),arr.end(),x) - arr.begin() ; 
              int left = pos-1 , right = pos ;
              while(k--){
                  if(right>=n or (left>=0 &&  abs(arr[left]-x) <= abs(arr[right]-x))) left--;
                  else right++;
              }
              for(int i=left+1 ; i<right ; ++i) res.push_back(arr[i]);
          }
        return res ;
    }
};