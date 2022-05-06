class Solution {
public:
    string removeDuplicates(string s) {
       int n = s.length() ;
       string st ;
       int i = 0 ;
       while(i<n){
           if(st.back()!=s[i] or st.empty()){
               st.push_back(s[i]);
           }else{
               st.pop_back();
           }
           i++;
       }
       string res = "" ;
       while(!st.empty()){
           char x = st.back();
           res.push_back(x);
           st.pop_back();
       }
        reverse(res.begin(),res.end());
        return res ;
    }
};