class Solution {
    
    static bool comp(string &s1, string &s2){
        string n1 = s1 + s2, n2 = s2 + s1;
        return n1 > n2;
    }
    
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> strs;
        
        for(int i = 0; i < n; i++){
            strs.push_back(to_string(nums[i]));
        }
        sort(begin(strs), end(strs), comp);
        // for(int i = 0; i < n; i++){
        //     cout<<strs[i]<<" ";
        // }
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += strs[i];
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};
