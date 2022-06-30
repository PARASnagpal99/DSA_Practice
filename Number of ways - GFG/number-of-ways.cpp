// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    long long func(vector<long long>&dp , int indx , int N){
        if(indx < 4){
            return 1 ;
        }
        if(dp[indx]!=-1) return dp[indx] ;
        long long ans = func(dp,indx-1,N) + func(dp,indx-4,N) ;
        
        return dp[indx] = ans ;
    }



    long long int arrangeTiles(int N){
        vector<long long>dp(N+1,-1);
        long long ans = func(dp,N,N);
        return ans ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends