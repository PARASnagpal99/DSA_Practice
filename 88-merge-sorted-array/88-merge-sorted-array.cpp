class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int first = 0 , second = 0 ;
    // if(nums1.size()==1 && nums1[i]<nums2[j]){    no need of that 
    //     nums1.clear();                  
    //     nums1.push_back(nums2[j]);
    // }
    
    for(int i=m ; i<m+n ; ++i) nums1[i] = INT_MAX ;    
        
        
      
    while(first < m+n && second<n ){
        if(nums1[first]<=nums2[second]){
              first++;
        }
        else if(nums1[first]>nums2[second]){
            
            for(int k=m+n-1 ; k>first ; k--){
                nums1[k]=nums1[k-1];
            }
            
            nums1[first]=nums2[second];
            second++;
            first++;
        }
    }
     while(second<n) nums1[first++] =  nums2[second++];
      
    } 
};