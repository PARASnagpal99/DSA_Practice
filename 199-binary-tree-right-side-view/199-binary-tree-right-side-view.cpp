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
    void func(int level , vector<int> &ans , TreeNode* node){
        if(!node) return ;
        if(level == ans.size()){
            ans.push_back(node->val);
        }
        func(level+1,ans,node->right);
        func(level+1,ans,node->left) ;
    }
    
    
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {} ;
        vector<int> ans ;
        func(0,ans,root);
        return ans ;
    }
};