class Solution {
public:
    #define ll long long 
    bool isPossible(vector<int>& target) {
        ll n = target.size() ;
        ll sum = accumulate(target.begin(),target.end(),0*1ll) ;
        
        if(n==1) return target[0] == 1 ;
        
       
        
        priority_queue<int> pq ;
        
        for(auto &it : target){
            pq.push(it) ;
        }
        
        while(pq.top() != 1){
             ll curr = pq.top() ;
             pq.pop() ;
             if(sum - curr == 1) return true ;
             int OLD = (curr) % (sum - curr) ;
             
             sum -= curr ;
             sum += OLD ;
             
             if(OLD == 0 or OLD == curr) return false ;
             
              pq.push(OLD) ;
        }
        
        
        return true ;
        
    }
};