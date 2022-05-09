class Solution {
public:
    void func(string &digits , int pos , string &temp , vector<string>&ans , vector<string>&mp ){
        if(pos>=digits.length()){
            ans.push_back(temp) ;
            return ;
        }
        
        for(auto &it : mp[digits[pos]-'0']){
            temp.push_back(it);
            func(digits,pos+1,temp,ans,mp);
            temp.pop_back();
        }
        
    }
    
    
    vector<string> letterCombinations(string digits) {
            if(digits.length()==0) return {} ;
            vector<string> ans ;
            vector<string> mp = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" };
            string temp = "" ;
            func(digits,0,temp,ans,mp);
            return ans ;
    }
};