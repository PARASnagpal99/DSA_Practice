/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
            if(root==NULL){
            return NULL ;
        }
        queue<Node*>q ;
        q.push(root) ;
        while(!q.empty()){
            vector<Node*>temp ;
            int sz = q.size() ;
            for(int i=0 ; i<sz ; ++i){
                Node *x = q.front() ;
                temp.push_back(x);
                q.pop() ;
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
            }
            for(int i=0 ; i<temp.size() ; ++i){
                  Node* y = temp[i] ;
                if(i!=temp.size()-1){
                  Node* z = temp[i+1] ;  
                  y->next = z ;
                }else{
                    y->next = NULL ;
                }
            }
        }
        return root ;
    }
};