// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public :
	bool isPrime(int nums){
	    if(nums == 2 or nums == 3) return true ;
	    if(nums%2 == 0 && nums > 2) return false ;
	    if(nums == 1) return true ;
	    
	    for(int i=3 ; i <= sqrt(nums) + 1 ; ++i){
	        if(nums%i == 0) return false ; 
	    }
	    return true ;
	}
	
	 int primeFactors(int n)
    {
        // to store the count of prime factors
        int ans = 0 ;
        // Print the number of 2s that divide n
        while (n % 2 == 0)
        {
            ans++;
            n = n/2;
        }

        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                ans++;
                n = n/i;
            }
        }

        // This condition is to handle the case when n
        // is a prime number greater than 2
        if (n > 2)
            ans++;
        return ans;
    }
	
	
    bool brainGame(vector<int>nums) {
        // we have to find total number of non prime factors       
        // 36 -> 18 -> 9 -> 3   cnt = 3 
        int count = 0 ;
        for(auto &it : nums){
            if(isPrime(it) == false) count++;
        }
        
        vector<int> arr(count,0) ; 
        int k = 0 ;
        for(auto &it : nums){
            if(!isPrime(it)){
                arr[k] = primeFactors(it) - 1  ;
                k++;
            }
           
        }
        
        int x = 0 ;
        for(int i=0 ; i<count ; ++i){
            x = x ^ arr[i] ;
        }
        
        return (x != 0) ;
        
        
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends