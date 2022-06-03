class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1) ;
        for(int i=0 ; i<nums1.size() ; ++i){
            int x = nums1[i] ;
            bool flag = false ;
            for(int k=0 ; k<nums2.size() ; ++k){
                if(nums2[k]==x){
                    flag = true ;
                }
                
                if(nums2[k]>x && flag){
                    res[i] = nums2[k];
                    break ;
                }
            }
            
        }
        return res ;
    }
};