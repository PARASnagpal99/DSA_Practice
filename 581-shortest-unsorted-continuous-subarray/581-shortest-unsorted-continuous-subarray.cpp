class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums ;
   //     map<int,int>mp ;
        sort(temp.begin(),temp.end(),[&](int a , int b){
            return a < b ;
        });
        // for(int i=0 ; i<temp.size() ; ++i){
        //     mp[temp[i]] = i ;
        // }
        int left = 0 ;
        for(int i=0 ; i<nums.size() ; ++i){
            if(nums[i]!=temp[i]){
                left = i ;
                break ;
            }
        }
        
        int right = 0 ;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            if(nums[i]!=temp[i]){
                right = i ;
                break ;
            }
        }
        if(right==left) return 0 ;
        return (right-left+1);
        
        
    }
};