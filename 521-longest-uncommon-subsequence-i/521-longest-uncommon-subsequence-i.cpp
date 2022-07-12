class Solution {
public:
    int findLUSlength(string a, string b) {
          int n = a.length() , m = b.length() ;
          if(a == b) return -1 ;
          return max(n,m) ;
    }
};