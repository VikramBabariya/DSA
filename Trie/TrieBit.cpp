/*
for 32 bit
*/

struct Node {
    Node* links[2];

    bool containsKey(int key) {
        return (links[key] != NULL);
    }

    void insertKey(int key) {
        Node* node = new Node();
        links[key] = node;
    }
};
class Trie {
    Node * root;

public:
    Trie() {
      root = new Node();
    }
 
    void insert(int num) {
      Node* node = root;
      for (int i = 31; i >= 0; i--) { 
        int bit = (num >> i) & 1;
        if (node->containsKey(bit) == false) {
          node->insertKey(bit);
        }
        node = node->links[bit];
      }
    }
};
