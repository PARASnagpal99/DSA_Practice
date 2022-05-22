class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length() ;
        int res = 0 ;
        for(int i=0 ; i<n ; ++i){
            int left = i , right = i ;
            while(left>=0 && right<n && s[left]==s[right]){
                res+=1;
                left--;
                right++;
            }
            left = i , right = i+1 ;
             while(left>=0 && right<n && s[left]==s[right]){
                res+=1;
                left--;
                right++;
            }
        }
        
        return res ;
    }
};