// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int arr[]) {
    vector<int> up , down ;
    sort(arr,arr+n) ;
    int cnt = (n+1)/2 ;
    int indx = n-1 ;
    while(cnt--){
        up.push_back(arr[indx]);
        indx--;
    }
    
    while(indx >= 0){
        down.push_back(arr[indx]);
        indx--;
    }
    reverse(down.begin(),down.end());
    
    int sum = 0 ;
    for(int i=0 ; i<up.size() ; ++i){
        sum += up[i] ;
    }
    
    for(int i=0 ; i<down.size() ; ++i){
        sum-=down[i] ;
    }
    
    if(sum <=0 ) return {-1} ;
    
    int a = 0 , b = 0 ;
    vector<int> res ;
    for(int i=0 ; i<n ; ++i){
        if(i&1){
            res.push_back(down[a]);
            a++;
        }else{
            res.push_back(up[b]);
            b++;
        }
    }
    

    return res ;
}
