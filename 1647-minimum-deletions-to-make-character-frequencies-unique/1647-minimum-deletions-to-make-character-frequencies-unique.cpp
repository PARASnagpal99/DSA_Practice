class Solution {
public:
    int minDeletions(string s) {
       unordered_map<char,int>hsh ;
        
       for(auto &it : s) hsh[it]++;
        
       vector<int> cnt ;
       for(auto &it : hsh){
           cnt.push_back(it.second);
       }
      
        int ans = 0 ;
        unordered_set<int> st ;
        for(int i=0 ; i<cnt.size() ; ++i){
            while(cnt[i] && st.find(cnt[i])!=st.end()){
                 ans++;
                 cnt[i]--;
            }
            st.insert(cnt[i]);
        }
        return ans ;
    }
};