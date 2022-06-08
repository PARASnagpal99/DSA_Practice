class Solution {
public:
    
    bool isValid(string &s , string &p , int k ,  vector<int> &removable){
        string temp = s ;
        for(int i=0 ; i<k ; ++i){
            s[removable[i]] = '#' ;
        }
        
        int i=0 , j = 0 ;
        int n = s.length() , m = p.length() ;
        while(i < n && j < m ){
            if(s[i]==p[j]){
                j++;
            }
            i++;
        }
        s = temp ;
        return (j==m);
    }
    
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int lo = 0 , hi = removable.size() ;
        int ans = 0 ;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            if(isValid(s,p,mid,removable)){
                ans = mid ;
                lo = mid+1 ;
            }else{
                hi = mid-1 ;
            }
        }
        return ans ;
    }
};