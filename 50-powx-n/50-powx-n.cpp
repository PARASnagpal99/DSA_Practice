class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1 ;
        
        if( n < 0){
            x = 1 / x ;
            n = abs(n) ;
        }
        
        double temp = myPow(x,n/2) ;
        double res = temp * temp ;
        if(n & 1) res *= (x*1ll) ;
        return res ;
    }
};