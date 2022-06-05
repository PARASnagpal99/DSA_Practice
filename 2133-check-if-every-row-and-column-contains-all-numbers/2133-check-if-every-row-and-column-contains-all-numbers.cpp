class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        for(int i=0 ; i<n ; ++i){
            unordered_set<int> st ;
            for(int j=0 ; j<n ; ++j){
                st.insert(matrix[i][j]);
            }
            if(st.size()<n) return false ;
            st.clear() ;
        }
        
        
        for(int i=0 ; i<n ; ++i){
            unordered_set<int> st ;
            for(int j=0 ; j<n ; ++j){
                st.insert(matrix[j][i]);
            }
            if(st.size()<n) return false ;
            st.clear() ;
        }
        
       return true ; 
        
        
    }
};