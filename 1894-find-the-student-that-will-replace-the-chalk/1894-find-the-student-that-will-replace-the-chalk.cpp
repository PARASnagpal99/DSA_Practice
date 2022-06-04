class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
         int i = 0 , n = chalk.size() ;
         k = k% accumulate(chalk.begin(),chalk.end(),0*1ll) ;
         while(chalk[i%n]<=k){
             k-=chalk[i%n];
             i++;
         }
        return i%n ;
    }
};