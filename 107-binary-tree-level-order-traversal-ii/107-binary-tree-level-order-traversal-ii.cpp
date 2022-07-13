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
    int func(TreeNode *root) {
      if (!root) return 0;
      return max(func(root->left),func(root->right))+1;
  }
    
    void bfs(vector<vector<int>> &ans, TreeNode *node, int level) {
        if (!node) return;
        ans[level].push_back(node->val);
        bfs(ans,node->left,level-1);
        bfs(ans,node->right,level-1);
 }
    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = func(root) ;
        
       vector<vector<int>> ans(depth,vector<int> {});
        
        bfs(ans,root,depth-1) ;
        
        return ans ;
        
    }
};