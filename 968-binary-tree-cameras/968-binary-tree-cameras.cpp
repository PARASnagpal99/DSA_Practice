/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 2 means at least one child node has camera so need to put camera on parent , its already being monitored 
    // 1 means leaf node or null or both the nodes are being monitored but has no camera on them so we will put the camera on parent 
    // 0 means if at least one child node is not being monitored so will put the camera here 
    int sum = 0 ;
    int dfs(TreeNode* source){
        if(source==NULL) return 1 ; // base case , need to put camera on parent of parent .
        int left_subtree = dfs(source->left);
        int right_subtree = dfs(source->right) ;
        
        if(left_subtree==0 or right_subtree==0){
            // we need to put camera here and mark it as monitored 
            sum++;
            return 2 ;
        }else if(left_subtree==2 or right_subtree==2){
            return 1 ;
        }else{
            // children are being monitored but have no camera , so we need to put camera on parent 
            return 0 ;
        }
        return -1 ;
    }
    
    int minCameraCover(TreeNode* root) {
         if(dfs(root)==0) sum++; // to check for root node .
         return sum ;
    }
};