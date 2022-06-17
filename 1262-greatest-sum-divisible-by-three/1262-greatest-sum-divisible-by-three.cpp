class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size() ;
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        int firstMin1 = INT_MAX/2  , secondMin1 = INT_MAX/2 ;
        int firstMin2 = INT_MAX/2  , secondMin2 = INT_MAX/2 ;
        
        
        if(sum % 3 == 0 ) return sum ;
        
        vector<int> num1 , num2 ;
        
        
        for(auto &it : nums){
            if(it%3==1) num1.push_back(it);
            if(it%3==2) num2.push_back(it);
        }
        
        sort(num1.begin(),num1.end());
        sort(num2.begin(),num2.end());
        
        if(num1.size() >= 1) firstMin1 = num1[0] ;
        if(num1.size() >= 2) secondMin1 = num1[1] ;
        
        if(num2.size() >= 1) firstMin2 = num2[0] ;
        if(num2.size() >= 2) secondMin2 = num2[1] ;
        
        
        
        if(sum % 3 == 1){
            return (sum - min(firstMin1 , firstMin2 + secondMin2)) ;
        }
      
        return (sum - min(firstMin2 , firstMin1 + secondMin1)) ;
       
        
        
        
    }
};