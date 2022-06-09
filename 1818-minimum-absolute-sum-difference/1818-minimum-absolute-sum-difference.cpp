class Solution {
public:
#include<bits/stdc++.h>
#define REP(it,n) for(int i=it; i<n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define ll long long
#define INF 1000000000
#define prDouble(x) cout << fixed << setprecision(10) << x  
#define endl '\n'
    
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        set<int> s(nums1.begin(),nums1.end());
        ll sum = 0 , diff = 0 ;
        for(int i=0 ; i<n ; ++i){
            ll temp = abs(nums1[i]-nums2[i]) ;
            sum+=temp ;
            if(temp > diff){
                 auto ind = s.lower_bound(nums2[i]);
                 if(ind!=s.end()){
                     diff = max(diff,temp-abs(*ind-nums2[i]));
                 }
                if(ind!=s.begin()){
                    ind--;
                    diff = max(diff,temp-abs(*ind-nums2[i]));
                } 
            }            
        }
        return (sum-diff)%mod ;
    }
};