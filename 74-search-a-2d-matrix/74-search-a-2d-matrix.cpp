class Solution {
public:
    bool func(vector<int> &arr , int target){
         int left = 0 , right = arr.size()-1 ;
         while(left<=right){
             int mid = left + (right-left)/2 ;
             if(arr[mid]==target) return true ;
             if(arr[mid]<target) left = mid + 1 ;
             else right = mid -1 ;
         }
        return false ;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n = matrix.size() ;
          for(int i=0 ; i<n ; ++i){
              if(func(matrix[i],target)) return true ;
          }
        return false ;
    }
};