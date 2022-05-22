class Solution {
public:
    int func(string &s , int left , int right){
         int n = s.length() , res = 0 ;
         while(left>=0 && right<n && s[left]==s[right]){
                res+=1;
                left--;
                right++;
            }
        return res ;
    }
    
    int countSubstrings(string s) {
        int n = s.length() ;
        int res = 0 , left , right ;
        for(int i=0 ; i<n ; ++i){
            left = i , right = i ;
            res+=func(s,left,right) ;
            
            left = i , right = i+1 ;
            res+=func(s,left,right) ;
        }
        
        return res ;
    }
};