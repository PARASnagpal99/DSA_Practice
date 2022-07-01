// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

/*

1 2 3 4 5 6 

2 4 6           1 2 3 
2 6               2
4




*/




class Solution {
  public:
    long long oddGame(long long N) {
              while(N & (N-1)){
                  N--;
              }
              return N ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.oddGame(N) << endl;
    }
    return 0;
}  // } Driver Code Ends