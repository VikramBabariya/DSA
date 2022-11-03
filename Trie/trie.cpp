/* 
  TC of insert, search word, search prefix : O(len of word)
*/

struct Node{
    Node* links[26];
  int wordCnt, prefixCnt;
    bool isTerminal;
    
    Node(){
        for(int i = 0; i < 26; i++) links[i] = NULL;
        wordCnt = 0;
        prefixCnt = 0;
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

    void insert(string &word){
        Node* currNode = root;
        for(auto c: word){
            if(currNode->containsKey(c) == false){
                currNode->insertKey(c); // making new ref + incrementing pc of ref
            }
            currNode = currNode->links[c - 'a']; // moving to next reference
            currNode->prefixCnt++; 
        }
        
        currNode->isTerminal = true;
        currNode->wordCnt++;
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
  
    int countWordsEqualTo(string &word){
        Node* currNode = root;
        for(auto c: word){
            if(currNode->containsKey(c) == 0) return 0;
            currNode = currNode->links[c - 'a']; // moving to next reference
        }
        if(currNode->isTerminal == false) return 0;
        return currNode->wordCnt;
    }

    int countWordsStartingWith(string &word){
        Node* currNode = root;
        for(auto c: word){
            if(currNode->containsKey(c) == 0) return 0;
            currNode = currNode->links[c - 'a']; // moving to next reference
        }
        return currNode->prefixCnt;
    }

    void erase(string &word){
        Node* currNode = root;
        for(auto c: word){
            currNode = currNode->links[c - 'a']; // moving to next reference
            currNode->prefixCnt--;
        }
        currNode->wordCnt--;
    }
};
