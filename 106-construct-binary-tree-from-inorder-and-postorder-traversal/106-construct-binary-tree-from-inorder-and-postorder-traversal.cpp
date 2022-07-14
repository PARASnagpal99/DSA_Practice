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
    TreeNode* func(vector<int>& inorder , int inStart , int inEnd , vector<int>& postorder , int postStart , int postEnd , map<int,int>& mp){
        
        if(inStart > inEnd or postStart > postEnd) return NULL ;
        
        TreeNode* root = new TreeNode(postorder[postStart]) ;
        
        int inorder_root = mp[postorder[postStart]] ;
        
        int right_length = inEnd - inorder_root ;
        
        root->right = func(inorder,inorder_root+1,inEnd , postorder , postStart+1 , postStart + right_length , mp) ;
        root->left  = func(inorder,inStart,inorder_root-1,postorder , postStart + right_length + 1 , postEnd , mp) ;
        
        return root ;
        
    }
    
    

    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() , m = postorder.size() ;
        reverse(postorder.begin(),postorder.end()) ;
        
        map<int,int> mp ;
        
        for(int i=0 ; i<n ; ++i){
            mp[inorder[i]] = i ;
        }
        
        
        TreeNode* root = func(inorder,0,n-1,postorder,0,n-1,mp) ;
        
        return root ;
        
    }
};