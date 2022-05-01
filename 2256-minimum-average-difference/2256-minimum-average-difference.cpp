class Solution {
private : 
public:
    #define ll long long 
    int minimumAverageDifference(vector<int>& nums) {
        ll n = nums.size() ;
        vector<ll>prefx(n) ;
        vector<ll>sufx(n)  ;
        prefx[0] = nums[0] ;
        for(ll i=1 ; i<n ; ++i){
            prefx[i]+=(prefx[i-1]+nums[i]);
        }
        sufx[n-1]=0;
        for(ll i=n-2 ; i>=0 ; i--){
            sufx[i]+=(sufx[i+1]+nums[i+1]);
        }
        vector<ll>res(n);
        for(ll i=0 ; i<n-1 ; ++i){
            res[i] = abs(prefx[i]/(i+1) - sufx[i]/(n-1-i));
        }
        res[n-1] = abs(prefx[n-1]/(n));
        ll ans = 10000000 , fin ;
        for(int i=0 ; i<n ; ++i){
            if(res[i]<ans){
                ans = res[i] ;
                fin = i ;
            }
        }
        return fin ;
    }
};