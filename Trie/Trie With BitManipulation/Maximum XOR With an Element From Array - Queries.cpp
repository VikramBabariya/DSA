/*
tc:o(nlogn + qlogq)
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


vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> ans(queries.size(), 0); 
    vector<pair<int, pair<int,int>>> offlineQueries; 

    sort(arr.begin(), arr.end()); 
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
    sort(offlineQueries.begin(), offlineQueries.end()); 

    int i = 0; 
    int n = arr.size(); 
    Trie trie; 

    for(auto &it : offlineQueries) {
        while(i < n && arr[i] <= it.first) { 
            trie.insert(arr[i]); 
            i++; 
        }
        if(i!=0) ans[it.second.second] = trie.findMax(it.second.first); 
        else ans[it.second.second] = -1; 
    }
    return ans; 
}
