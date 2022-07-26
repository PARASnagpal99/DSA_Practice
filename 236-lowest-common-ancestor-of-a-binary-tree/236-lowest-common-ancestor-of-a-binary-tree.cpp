/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode* root , vector<int> &path , int target){
        if(root == NULL) return false ;
        
        path.push_back(root->val) ;
        
        if(root->val == target) return true ;
        
        bool l = func(root->left,path,target) ;
        bool r = func(root->right,path,target) ;
        bool check = l | r ;
        if(check) return true ;
        
        path.pop_back() ;
        return false ;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL or root == p or root == q) return root ;
        vector<int> path1 ;
        vector<int> path2 ;
        
        func(root,path1,p->val);
        func(root,path2,q->val);
        
        int i = 0 , j = 0 ;
        
        while(i < path1.size() && j < path2.size() && path1[i] == path2[j]){
                i++ ;
                j++ ;
        }
        
        i--;
        
        TreeNode* ans = new TreeNode(path1[i]) ;
        
        return ans ;
        
    }
};