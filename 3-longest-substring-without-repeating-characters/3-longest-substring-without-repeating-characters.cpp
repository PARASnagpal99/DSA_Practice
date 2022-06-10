class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length() ;
        if(n==0) return 0 ;
        if(n==1) return 1 ;
        unordered_set<int> st ;
        int start = 0 , end = 0 ;
        int ans = 0 ;
        while(end < n){
            if(st.find(s[end])==st.end()){
                st.insert(s[end]);
                ans = max(ans,end-start+1);
                end++;
            }else{
                st.erase(s[start]);
                start++;
            }
        }
        
        return ans ;
        
    }
};