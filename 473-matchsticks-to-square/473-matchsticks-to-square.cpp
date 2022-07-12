class Solution {
 bool backtrack(int curr,int &target,int partitionNum,vector<int>&match,int index,vector<bool>&seen){
        if(partitionNum==3){
            return true;
        } else if(curr==target){
            return backtrack(0,target,partitionNum+1,match,0,seen);
        } else {
            for(int i=index;i<match.size();i++){
                if(!seen[i]){
                    seen[i]=true;
                    if(backtrack(curr+match[i],target,partitionNum,match,i+1,seen)){
                        return true;
                    }
                    seen[i]=false;
                }
            }
            return false;
        }
    }
public:
    bool makesquare(vector<int>& match) {
        int total=0;
        for(int i=0;i<match.size();i++){
            total=total+match[i];
        }
        if(total%4!=0){
            return false;
        } else {
            int target=total/4;
            vector<bool>seen(match.size(),false);
            return backtrack(0,target,0,match,0,seen);
        }
    }
};