// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        int msb = 0 ;
        for(int i=31 ; i>=0 ; --i){
            if(N & (1 << i)){
                msb = i ;  // we can also find this using log2(N)
                break ;
            }
        }
        
        int num = 0 ;
        for(int i=0 ; i<=msb ; ++i){
            num = num | (1 << i) ;
        }
        
        return {abs(N-num) , num } ;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends