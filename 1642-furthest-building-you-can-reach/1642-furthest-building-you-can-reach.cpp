class Solution {
public:
    #define ll long long 
    /*
    14 , 3 , 19 , 3 
    
    use a multiset to store the differences as you traverse the array ;
    if size of multisets > ladders , subtract the top difference from the bricks and erase it from the multiset .
    when size > ladders and bricks < st.top break and return the current index ;
    
    */
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        ll n = heights.size() ;
        
        priority_queue<ll, vector<ll> ,greater<ll> > pq;
        
        for(ll i=0 ; i<n-1 ; ++i){
            
            ll diff = heights[i+1] - heights[i] ;
            if(diff < 0) continue ;
            if(diff > 0) pq.push(diff) ;
            
            if(pq.size() > ladders){
                auto curr = pq.top() ;
                if(bricks < curr) return i ;
                bricks-=curr;
                pq.pop() ;
            }
            
        }
        
        return n-1 ;
        
        
    }
};