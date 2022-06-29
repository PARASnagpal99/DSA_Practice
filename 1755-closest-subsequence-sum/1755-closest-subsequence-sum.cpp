class Solution {
public:
    
    vector<int> SubsetSum(vector<int> :: iterator start , vector<int> :: iterator end){
        
        vector<int> sum ;
        sum.push_back(0) ;
        
        for(auto it = start ; it != end ; ++it){
               int sz = sum.size() ;
               for(int i=0 ; i<sz ; ++i){
                    sum.push_back(*it + sum[i]) ;
               }
        }
        
        sort(sum.begin(),sum.end()) ;
        sum.erase(unique(sum.begin(),sum.end()),sum.end());
        return sum ;
    }
    
    
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size() ;
        int k = n/2 ;
        
        vector<int> leftSS = SubsetSum(nums.begin(),next(nums.begin(),k));
        vector<int> rightSS = SubsetSum(next(nums.begin(),k),nums.end());
        
        
        int i=0 , j = rightSS.size()-1 ;
        int ans = abs(goal) ;
        
        while(i<leftSS.size() && j >=0 ){
            int diff = leftSS[i] + rightSS[j] ;
            ans = min(ans , abs(goal-diff) ) ;
            if(ans==0) break ;
            else if(diff > goal) j--;
            else i++;
        }
        
        return ans ;
        
    }
};