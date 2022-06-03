class Solution {
public:
    /*
     (*))
      
    
    */
    
    bool checkValidString(string s) {
            int val1 =0 , val2 = 0 ;
         for(auto &it : s){
             if(it=='(' or it=='*') val1++;
             else val1--;
             
             if(val1<0) return false ;
         }
        
        for(int i=s.length()-1 ; i>=0 ; i--){
             if(s[i]==')' or s[i]=='*') val2++;
             else val2--;
            if(val2<0) return false ;
        }
        
        return true ;
        
    }
};