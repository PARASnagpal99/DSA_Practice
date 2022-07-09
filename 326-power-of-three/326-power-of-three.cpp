class Solution {
public:
    // 27->9->3->1
    // 15->5->1
    bool isPowerOfThree(int n) {
        
        while(n % 3 == 0 && n!=0){
              n = n/3 ;
        }
        
        return n==1 ;
        
    }
};