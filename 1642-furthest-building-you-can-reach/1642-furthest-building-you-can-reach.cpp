class Solution {
public:
    #define ll long long 
    /*
    14 , 3 , 19 , 3 
    
    use a multiset to store the differences as you traverse the array ;
    if size of multisets > ladders , subtract the top difference from the bricks and erase it from the multiset .
    when size > ladders and bricks < st.top break and return the current index ;
    
    */
    
    
    
    
    
    
    bool isValid(vector<int>&heights , int bricks , int ladders , int k){
           vector<int> diff ;
           
        for(int i=1 ; i<=k ; i++){
            int d = heights[i] - heights[i-1] ;
            if(d > 0) diff.push_back(d) ;
        }
        
        sort(diff.rbegin(),diff.rend()) ;
            
        for(int i=ladders ; i<diff.size() ; ++i){
              if(bricks < diff[i] ) return false ;
              bricks-=diff[i] ;
        }
        
        return bricks>=0 ;
        
    }
    
    
    
    

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         ll n = heights.size() ;
        
//         priority_queue<ll, vector<ll> ,greater<ll> > pq;
        
//         for(ll i=0 ; i<n-1 ; ++i){
            
//             ll diff = heights[i+1] - heights[i] ;
//             if(diff < 0) continue ;
//             if(diff > 0) pq.push(diff) ;
            
//             if(pq.size() > ladders){
//                 auto curr = pq.top() ;
//                 if(bricks < curr) return i ;
//                 bricks-=curr;
//                 pq.pop() ;
//             }
            
//         }
        
//         return n-1 ;
        
        
         // using Binary search on answer 
         int n = heights.size() ;  
         int lo = 0 , hi = n-1 ; 
         int ans = 0 ;
         while(lo <= hi){
             int mid = lo + (hi-lo)/2 ;
             if(isValid(heights,bricks,ladders,mid)){
                 ans = mid  ;
                 lo = mid+1 ;
             }else{
                 hi = mid-1 ;
             }
         }
        
        
        
        
        return ans ;
        
        
        
        
        
        
        
        
        
        
    }
};