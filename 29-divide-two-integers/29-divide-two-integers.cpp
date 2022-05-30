class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1 ;
        bool pos = false ;
        if((dividend>0 && divisor>0) or (dividend<0 && divisor<0)) pos = true ;
        unsigned int num1 = abs(dividend) ;
        unsigned int num2 = abs(divisor) ;
        unsigned int res = 0 ;
        while(num1>=num2){
            short i = 0 ;
            while (num1 > (num2 << (i+1))){
                i++;
            }
            res += (1 << i) ;
            num1-=(num2 << i) ;
        }
        
        if(res==(1 << 31) && pos) return INT_MAX ;
        return pos ? res : -res ;
    }
};