class Solution {
public:
    #define ll long long 
    int arrangeCoins(int n) {
        ll ans = n ;
        return (-1+sqrt(1+8*ans))/2 ;
        
    }
};