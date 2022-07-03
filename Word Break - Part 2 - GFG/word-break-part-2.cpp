// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
     void func(int indx , string &s , unordered_set<string>st , string temp , vector<string>&res ){
        if(indx == s.size()){
            temp.pop_back() ;
            res.push_back(temp) ;
        }
        
        string str = "" ;
        
        for(int i=indx ; i < s.size() ; ++i){
            str.push_back(s[i]);
            if(st.count(str)){
                 func(i+1,s,st,temp+str+" ",res);       
            }
        }
        
    }


    vector<string> wordBreak(int t, vector<string>& dict, string s)
    {
        vector<string> res ;
        int n = s.length() ;
        unordered_set<string> st ;
        for(auto &it : dict){
            st.insert(it) ;
        }
        
        string curr = "" ;
        vector<string> ans ;
        func(0,s,st,curr,ans);
        return ans ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends