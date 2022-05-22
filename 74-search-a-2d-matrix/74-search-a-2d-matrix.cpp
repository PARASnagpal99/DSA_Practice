class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size() , m = matrix[0].size() ;
         if(target < matrix[0][0] || target > matrix[n-1][m-1])  return 0;
         int start = 0 , end = n-1 ;
         int col = m-1 , indx ;
         while(start<=end){
             int mid = start + (end-start)/2 ;
             if(matrix[mid][col]==target) return true ;
             else if(matrix[mid][col]>target) end = mid-1 ;
             else start = mid + 1 ;
         }
        
        if(start==n) start = n-1 ;
        if(matrix[start][0]>target) start--;
        int x = start ;
        auto it = lower_bound(matrix[x].begin(),matrix[x].end(),target) ;
        if(it!=matrix[x].end() && *it==target) return true ;
        else return false ;
        
    }
};