class Solution {
public:
    /*
    
    start = 0 , jump 1 
    curr = 1 , jump : 0 , 1 , 2 ; last jump : 1
    curr = 3 , last jump : 2 , jump : 1,2,3
    // available options : 3+1,3+2,3+3
    // we will unvisit a node after jumping on it 
    
    we will maintain a queue to do bfs over the paths , also we will push in queue only when stone is available 
    if we reach the last stone return true ;
    if(queue becomes empty and we dont reach last stone){
       return false ;
    }
    
    
    
    */
    bool func(int start , int end , unordered_set<int> &visit , set<pair<int,int>> &visited ){
        
         queue<pair<int,int>> q ;
         q.push({start,-1}) ;
         visited.insert({start,-1});
        
         while(!q.empty()){
             auto curr = q.front() ;
             q.pop() ;
             if(curr.first == end) return true ;
             int pos = curr.first ;
             int jump = curr.second ;
             int jump1 = 1 , jump2 =  1 , jump3 = 1 ;
             if(jump!=-1) jump1 = jump ; jump2 = jump-1 ; jump3 = jump+1 ;
             
             if(jump1 > 0){
                  int pos1 = pos + jump1 ;
                  if(visit.count(pos1) && visited.find({pos1,jump1}) == visited.end()){
                      q.push({pos1,jump1}) ;
                      visited.insert({pos1,jump1});
                  }
             }
             
             if(jump2 > 0){
                 int pos2 = pos + jump2 ;
                  if(visit.count(pos2) && visited.find({pos2,jump2})==visited.end()){
                      q.push({pos2,jump2}) ;
                      visited.insert({pos2,jump2});
                  }
             }
             
             if(jump3 > 0){
                  int pos3 = pos + jump3 ;
                  if(visit.count(pos3) && visited.find({pos3,jump3}) == visited.end()){
                      q.push({pos3,jump3}) ;
                      visited.insert({pos3,jump3});
                  }
             }
         }
        
         
        return false ;
    }
    
    
    bool canCross(vector<int>& stones) {
         int n = stones.size() ;
         int start = stones[0] ;
         int end = stones[n-1] ;
         
         unordered_set<int> visit(stones.begin(),stones.end());
         set<pair<int,int>> visited ;
         
         bool ans = func(start,end,visit,visited);
         return ans ;
        
    }
};