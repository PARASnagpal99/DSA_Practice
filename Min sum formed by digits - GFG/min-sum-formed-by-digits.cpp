// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    #define ll long long  
    /*
       6 , 8 , 4 , 5 , 2 , 3 
       2 , 3 , 4 , 5 , 6 , 8 
       
       first -> 2 4 6 
       second -> 3 5 8
       
       0 , 3 , 4 , 5 , 7 
       first -> 0 , 4 , 7
       second -> 3 5 
       
    
    */
    long long int minSum(int arr[], int n)
    {
        
        sort(arr,arr+n);
        long long int num1=0;
        long long int num2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                num1=num1*10+arr[i];
            }
            else{
                num2=num2*10+arr[i];
            }
        }
        return num1+num2;
    }
        
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends