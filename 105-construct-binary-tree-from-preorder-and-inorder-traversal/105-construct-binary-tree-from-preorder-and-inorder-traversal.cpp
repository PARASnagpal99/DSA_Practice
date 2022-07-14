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
    TreeNode* func(vector<int> &preorder , int PreStart , int PreEnd , vector<int> &inorder , int inStart , int inEnd , map<int,int> &mp){
        
        if(PreStart > PreEnd or inStart > inEnd) return NULL ;
        
        TreeNode* root = new TreeNode(preorder[PreStart]) ;
        
        int Inorder_root = mp[preorder[PreStart]] ;
        
        int left_length = Inorder_root - inStart ;
        
        root->left = func(preorder,PreStart+1,PreStart+left_length,inorder,inStart,Inorder_root-1,mp) ;
        
        root->right = func(preorder,PreStart+left_length+1,PreEnd,inorder,Inorder_root+1,inEnd,mp) ;
        
        return root ;
    }
    
    

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size() , m = inorder.size() ;
        map<int,int> mp ;
        
        for(int i=0 ; i<inorder.size() ; ++i){
            mp[inorder[i]] = i ;
        }
        
        TreeNode* root = func(preorder,0,n-1,inorder,0,m-1,mp) ;
        return root ;
        
        
    }
};