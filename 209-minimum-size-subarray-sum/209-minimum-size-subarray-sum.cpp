class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n = arr.size() ;
        int start = 0 , end = 0 ;
        int sum = 0 ;
        int len = INT_MAX ;
        while(end < n){
            sum+=arr[end] ;
            while(sum>=target){
                len = min(len,end-start+1) ;
                sum-=arr[start];
                start++;
            }
            end++;
        }
        if(len==INT_MAX) return 0 ;
        return len ;
    }
};