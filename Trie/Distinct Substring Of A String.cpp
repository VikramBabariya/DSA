/*
tc:o(n^2)
sc:o(complex)
*/

struct Node{
    Node* links[26];
    
    Node(){
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }
    
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }  
    
    void insertKey(char c){
        Node* node = new Node(); // creating new reference
        links[c - 'a'] = node;
    }
};

int countDistinctSubstring(string s)
{
    Node* root = new Node();
    int n = s.size(), dist = 0;
    
    for(int i = 0; i < n; i++){
        Node* node = root;
        for(int j = i; j < n; j++){
            if(node->containsKey(s[j]) == false){
                dist++;
                node->insertKey(s[j]);
            }
            node = node->links[s[j] - 'a'];
        }
    }
    return dist + 1;
}
