class Solution {
public:
    void solve(int n , vector<char> &arr ,int indx , int &count , int last ){
         if(indx>=n){
             count++;
             return ;
         }
        for(int i=last ; i<arr.size() ; ++i){
            solve(n,arr,indx+1,count,i);   
        }
    }
    
    int countVowelStrings(int n) {
          vector<char> arr = {'a','e','i','o','u'};
          int count = 0 ;
          solve(n,arr,0,count,0);
          return count ;
    }
};