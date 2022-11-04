/*
tc:o(n * AvgLen) 
sc:o(complex)
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

    bool isComplete(string word) {
        Node* currNode = root;
        for(auto c: word){
            if(currNode->containsKey(c) == false) return false;
            currNode = currNode->links[c - 'a']; // moving to next reference
            if(currNode->isTerminal == false) return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie* trie = new Trie();
    for(auto word: a){
        trie->insert(word);
    }
    
    string ans = "";
    for(auto word: a){
        if(trie->isComplete(word)){
            int len = word.size(), maxLen = ans.size();
            if(len > maxLen) ans = word;
            else if(len == maxLen){
                if(word < ans) ans = word;
            }
        }
    }
    
    return (ans.size() == 0) ? "None" : ans;  
}
