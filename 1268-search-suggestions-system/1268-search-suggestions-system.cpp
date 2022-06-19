class Node{
    private : Node* links[26] ;
              vector<int> indx ; // to store the indices 
    public :
    bool containsKey(char ch){
        return links[ch-'a']!=NULL ;
    }
        
    void put(char ch , Node* node){
        links[ch-'a'] = node ;
    }
    
    Node* get(char ch){
        return links[ch-'a'] ;
    }
    
    void addIndex(int i){
        indx.push_back(i) ;
    }
    
    vector<int> getindx(){
        return indx ;
    }
    
};

class Trie{
  private : Node* root ;
  public :
    Trie() {
        root = new Node() ;
    }
    
    void insert(string &word , int indx){
        Node* node = root ;
        for(int i=0 ; i<word.length() ; ++i ){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->addIndex(indx);
        }
    }
    
    
    vector<int> search(string key){
        Node* node = root ;
        for(auto &ch : key){
            if(!node->containsKey(ch)){
                return {} ;
            }
            node = node->get(ch);
        }
        vector<int> res = node->getindx();
        if(res.size() > 3){
            res.resize(3);
        }
        return res ;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
            Trie* trie = new Trie() ;
            sort(products.begin(),products.end());
            int n = products.size() ;
        
        for(int i=0 ; i<n ; ++i){
            trie->insert(products[i],i);
        }
        
        vector<vector<string>>res ;
        string s ;
        for(int i=0 ; i<searchWord.length() ; ++i){
            s+=searchWord[i];
            vector<int> prefxIndx = trie->search(s);
            vector<string> temp ;
            for(auto &it : prefxIndx){
                temp.push_back(products[it]);
            }
            res.push_back(temp);
        }
        return res ;
    }
};