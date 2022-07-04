// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int cnt = 0 ;
        for(int i=0 ; i<=31 ; ++i){
            if(b & (1 << i)) cnt++;
        }
        int ans = 0 ;
        for(int i=31 ; i>=0 ; i--){
            
            if(a & (1 << i) && cnt > 0){
                ans = ans | (1 << i) ;
                cnt--;
            }
        }
        
        for(int i=0 ; i<=31 ; ++i){
            if(cnt > 0 && !(a & (1 << i))){
                ans = ans | (1 << i) ;
                cnt--;
            }
        }
        
        return ans ;
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends