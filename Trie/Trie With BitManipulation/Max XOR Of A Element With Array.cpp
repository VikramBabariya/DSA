/*
tc:o(n)
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
 
    int findMax(int x) {
      Node* node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (node->containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node->links[!bit];
        } else {
          node = node->links[bit];
        }
      }
      return maxNum;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(), maxi = -1;
        Trie* trie = new Trie();

        for(auto num: nums){
            trie->insert(num);
        }

        for(auto x: nums){
            int maxXor = trie->findMax(x);
            maxi = max(maxi, maxXor);
        }
        return maxi;
    }
};
