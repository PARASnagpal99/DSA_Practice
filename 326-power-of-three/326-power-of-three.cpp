class Solution {
public:
    // 27->9->3->1
    // 15->5->1
    bool isPowerOfThree(int n) {
        if(n == 1) return true ;
        if(n == 0) return false;
        if(n%3) return false ;
        bool ans = isPowerOfThree(n/3) ;
        return ans ;
        
    }
};