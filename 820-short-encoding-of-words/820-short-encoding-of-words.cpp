class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
         unordered_set<string> st ;
         for(auto &it : words){
             st.insert(it);
         }
        
        for(auto &it : words){
            for(int i=1  ; i<it.length() ; ++i){
                 st.erase(it.substr(i));    
            }
        }
        int ans = 0 ;
        for(auto &it : st){
            ans += (it.length() + 1);
        }
        return ans ;
        
    }
};