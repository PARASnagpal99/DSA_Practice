struct Node{
    // basic structure of trie , it contains a hashmap with lot of references and a flag 
    Node* links[26];
    bool flag = false ;
    
    // check if the reference trie is present or not 
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL) ;
    }
    
    // creating reference trie node 
    void put(char ch , Node* node){
        links[ch-'a'] = node ;
    }
    
    // to get the next node for traversal 
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    // setting flag to the true at the end of word 
    void setEnd(){
        flag = true ;
    }
    
    // checking if the word is completed or not 
    bool isEnd(){
        return flag ;
    }
    
} ;

class Trie {
private : Node* root ;
public:
    Trie() {
        // creating new object 
        root = new Node() ;
    }
    
    void insert(string word) {
        Node *node = root ;   // initializing dummy node pointing to the root initially 
        for(int i=0 ; i<word.size() ; ++i){
            if(!(node->containsKey(word[i]))){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd() ;
    }
    
    bool search(string word) {
        Node* node = root ;
        for(int i=0 ; i<word.size() ; ++i){
            if(!(node->containsKey(word[i]))){
                return false ;
            }
            node = node->get(word[i]);
        }
        return node->isEnd() ;
    }
    
    bool startsWith(string prefix) {
        Node* node = root ;
         for(int i=0 ; i< prefix.size() ; ++i){
            if(!(node->containsKey(prefix[i]))){
                return false ;
            }
            node = node->get(prefix[i]);
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */