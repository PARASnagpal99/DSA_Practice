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
class BSTIterator {
private :
#define pb push_back
vector<int>arr ;
int i = 0 ;
public:

    void dfs(TreeNode* root){
        if(!root) return ;
        if(root!=NULL){
            dfs(root->left);
            arr.pb(root->val);
            dfs(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        int ans = arr[i] ;
        i++;
        return ans ;
    }
    
    bool hasNext() {
        int n = arr.size();
        if(i<n) return true ;
        else 
            return false ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */