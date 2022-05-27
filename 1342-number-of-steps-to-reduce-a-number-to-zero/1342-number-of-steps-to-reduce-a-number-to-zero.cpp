class Solution {
public:
    /*
    14 ->    0 1 1 1 0      
    14 -> 7  0 0 1 1 1
    7  -> 6  0 0 1 1 0
    6  -> 3  0 0 0 1 1
    3  -> 2  0 0 0 1 0 
    2  -> 1  0 0 0 0 1 
    1  -> 0  0 0 0 0 0 
    
    
    
    */
    int numberOfSteps(int num) {
          int cnt = 0 ;
          while(num){
              if(num&1){
                  num-=1 ;
              }else{
                  num/=2 ;
              }
              cnt++;
          }
        return cnt ;
    }
};