class Solution {
public:
    int findMin(vector<int>& arr) {
         int n = arr.size() ;
         int left = 0 , right = n-1 ;
         while(left<=right){
             if(arr[left]<=arr[right]){
                   return arr[left] ;   // 0 rotation , puri array hi sorted hai ;
             }
             int mid = left + (right-left)/2 ;
             int prev = (mid-1+n)%n ; // middle se piche vala element ;
             if(arr[mid]<=arr[prev]) return arr[mid] ;
             else if(arr[mid]>=arr[left]) left = mid+1 ;
             else if(arr[mid]<=arr[right]) right = mid-1 ;
         }
        return -1 ;
    }
};