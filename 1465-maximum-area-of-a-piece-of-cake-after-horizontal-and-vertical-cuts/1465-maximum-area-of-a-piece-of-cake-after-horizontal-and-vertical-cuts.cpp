class Solution {
public:
    #define ll long long
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        hc.push_back(h) ;
        vc.push_back(w) ;
        
        int mod = 1e9 + 7 ;
        
        ll mxlen = 0 ;
        ll mxBr = 0 ;
        
        for(int i=0 ; i<hc.size() ; ++i){
            if(i==0){
                mxlen = max(mxlen,(hc[i]-0)*1ll) ; 
            }else{
                mxlen = max(mxlen,(hc[i]-hc[i-1])*1ll);
            }
        }
        
        
        for(int i=0 ; i<vc.size() ; ++i){
            if(i==0){
                mxBr = max(mxBr,(vc[i]-0)*1ll) ; 
            }else{
                mxBr = max(mxBr,(vc[i]-vc[i-1])*1ll);
            }
        }
        
        long long  area = ((mxlen)%mod * (mxBr)%mod) % mod ;
        return (int)(area%mod) ;
        
    }
};