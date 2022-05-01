class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length() , m = t.length() ;
        int count = 0 ;
        string str = "";
        for(int i=n-1 ; i>=0 ; i--){
            if(s[i]=='#'){
                count++;
            }else if(count>0){
                count--;
            }else{
                str+=s[i];
            }
        }
        count=0;
        string str1 = "";
        for(int i=m-1 ; i>=0 ; i--){
            if(t[i]=='#'){
                count++;
            }else if(count>0){
                count--;
            }else{
                str1+=t[i];
            }
        }
        
        return str==str1 ;
    }
};