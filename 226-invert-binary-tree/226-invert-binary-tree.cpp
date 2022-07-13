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
    TreeNode* invertTree(TreeNode* root) {
//         if(!root) return root ;
//         if(root->left == NULL && root->right == NULL) return root ;
        
//         queue<TreeNode*> q ;
//         q.push(root) ;
        
//         while(!q.empty()){
//             auto curr = q.front() ;
//             q.pop() ;
            
            
//             if(curr->left) q.push(curr->left) ;
//             if(curr->right)q.push(curr->right) ;
            
//             TreeNode* temp = curr->left ;
//             curr->left = curr->right ;
//             curr->right = temp ;
            
//         }
        
        
//         return root ;
        
        
        
        
        if(!root) return root ;
        if(root->left == NULL && root->right == NULL) return root ;
        
        TreeNode* temp = root->left ;
        root->left = root->right ;
        root->right = temp ;
        
        invertTree(root->left) ;
        invertTree(root->right) ;
        
        return root ;
    }
};