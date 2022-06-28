class Solution {
public:
    int minDeletions(string s) {
       vector<int> hsh(26, 0);
        
       for(auto &it : s) hsh[it-'a']++;
        
       int ans = 0 ;
       sort(hsh.rbegin(),hsh.rend());
       int mx = s.size() ;
         
       for(int i=0 ; i<26 && hsh[i]>0 ; ++i){
           
           if(hsh[i] > mx){
               ans += (hsh[i] - mx) ;
               hsh[i] = mx ;
           }
           mx = max(0,hsh[i]-1);
       } 
        
       return ans ; 
    }
};