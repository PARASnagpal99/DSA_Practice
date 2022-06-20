struct Node{
    Node* link[2] = {NULL};
    
    bool containsKey(int bit){
        return (link[bit] != NULL);
    }
    void put(int bit,Node* node){
        link[bit]= node;
    }
    Node* get(int bit){
        return link[bit];
    }

};

class Trie{
    private : Node* root ;
    public : 
    Trie(){
        root = new Node() ;
    }
    
    void insert(int num){
        Node* node = root ;
        
        for(int i=31 ; i>=0 ; i--){
            int bit ;
            if(num & (1 << i)){
                bit = 1 ;
            }else {
                bit = 0 ;
            }
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
             node = node->get(bit);
        }
       
    }
       
    int findMax(int num){
        Node* node = root ;
        int maxNum = 0 ;
        for(int i=31 ; i>=0 ; i--){ 
            int bit ;
            if(num & (1 << i)){
                bit = 1 ;
            }else {
                bit = 0 ;
            }
            
            if(node->containsKey(!bit)){
                maxNum = maxNum | (1 << i) ;
                node = node->get(!bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxNum ;
    }
        
};



class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
         if(nums.size() == 0 ) {
            return 0;
        }
        
        Trie trie ;
        int n = nums.size() ;
        for(auto &it : nums){
            trie.insert(it);
        }
        int maxi = 0 ;
        for(auto &it : nums){
           maxi = max(maxi,trie.findMax(it));    
        }
        return maxi ;
        
        
        
    }
};