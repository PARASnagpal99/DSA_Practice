class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        int n = nums.size() ;
        
        for(int i=0 ; i<n ; ++i){
            nums[i] = nums[i] + (nums[nums[i]]%n)*n ;
        }
        
        for(int i=0 ; i<n ; ++i){
            nums[i] = nums[i]/n ;
        }
        
        
        return nums ;
        
        
        
        
        
        
        
        /*
        
        we have to represent nums[i] with a number from which we can obtain both original nums[i] and ans[i] in O(1) operation 
        
        nums = a + b*n => from this we can get both a and b .
        
        a = nums%n , b = nums/n 
        
        init = 2 , ans = 3 
        newNum = 2 + 3*10 = 32 
        ans = 32/10 = 3 
        init = 32%10 = 2 

        
        
        newNums[i] = nums[i] + (nums[nums[i]] % n)*n ;
        
        
        
        
        
        
        
        
        */
        
        
    }
};