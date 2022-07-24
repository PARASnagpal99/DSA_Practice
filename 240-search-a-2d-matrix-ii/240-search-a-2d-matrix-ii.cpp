class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size() ;
        for(int i=0 ; i<n ; ++i){
            int indx = lower_bound(matrix[i].begin(),matrix[i].end(),target) - matrix[i].begin() ;
            if((indx <= m-1 ) && matrix[i][indx] == target) return true ;
        }
        
        return false ;
        
    }
};