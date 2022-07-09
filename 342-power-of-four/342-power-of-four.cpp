class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false ;
        if(n == 1) return true ;
        
        if(n & 1) return false ;
        
        if( n & (n-1) ) return false ;
        
        if( (n-1) % 3 ) return false ;
        
        return true ;
        
    }
};