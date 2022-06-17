class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length() ;
        int best_start = 0 ;
        int best_len = 0 ;
        
        for(int i=0 ; i<n ; ++i){
            
            // odd length 
            int left = i , right = i ;
            while(left >=0 && right < n && s[left]==s[right]){
                if(right-left+1 > best_len){
                    best_len = right-left+1 ;
                    best_start = left ;
                }
                left--;
                right++;
            }
            
            // even length 
            left = i , right = i+1 ;
            while(left >=0 && right < n && s[left]==s[right]){
                if(right-left+1 > best_len){
                    best_len = right-left+1 ;
                    best_start = left ;
                }
                left--;
                right++;
            }
            
        }
        
        return s.substr(best_start,best_len) ;
        
    }
};