/* 
  TC of insert, search word, search prefix : O(len of word)
*/

struct Node{
    Node* links[26];
    bool isTerminal;
    
    Node(){
        for(int i = 0; i < 26; i++) links[i] = NULL;
        isTerminal = false;
    }
    
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }  
    
    void insertKey(char c){
        Node* node = new Node(); // creating new reference
        links[c - 'a'] = node;
    }
};


class Trie {
    Node* root;
public:
    
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* currNode = root;
        for(auto c: word){
            if(currNode->containsKey(c) == false){
                currNode->insertKey(c);
            }
            currNode = currNode->links[c - 'a']; // moving to next reference
        }
        
        currNode->isTerminal = true;
    }

    bool search(string word) {
        Node* currNode = root;
        for(auto c: word){
            if(currNode->containsKey(c) == false) return false;
            currNode = currNode->links[c - 'a']; // moving to next reference
        }
        return currNode->isTerminal;
    }

    bool startsWith(string prefix) {
        Node* currNode = root;
        for(auto c: prefix){
            if(currNode->containsKey(c) == false) return false;
            currNode = currNode->links[c - 'a']; // moving to next reference
        }
        return true;
    }
};
