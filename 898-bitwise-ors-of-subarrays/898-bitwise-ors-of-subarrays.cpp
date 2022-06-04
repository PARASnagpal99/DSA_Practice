class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
         unordered_set<int> st ;
        
       for(int i=0 ; i<arr.size() ; ++i){
            st.insert(arr[i]);
            for(int j=i-1 ; j>=0 ; j--){
                if((arr[i]|arr[j]) == arr[j]) break ;
                arr[j] |= arr[i] ;
                st.insert(arr[j]) ;
            }   
       } 
       
        return st.size() ;
    }
};