class Solution {
    
    bool isPal(string s, int start, int end){
        while(start <= end)
            if(s[start++] != s[end--])
                return false;
        return true;
    }
    
    void service(int ind, string s, int n, vector<string> &part, vector<vector<string>> &ans){
        if(ind == n){
            ans.push_back(part);
            return;
        }
        
        for(int i = ind; i < n; i++){
            if(isPal(s, ind, i)){
                part.push_back(s.substr(ind, i-ind+1));
                service(i+1, s, n, part, ans);
                part.pop_back();
            }
        }
    }
                                                                                         
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        int n = s.size();
        service(0, s, n, part, ans);
        return ans;
    }
};
