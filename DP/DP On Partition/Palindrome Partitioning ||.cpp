#include<bits/stdc++.h>

bool isPal(string &s){
    string s1 = s;
    reverse(begin(s1), end(s1));
    return s1 == s;
}

int minPart(int i, string &s, int n, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    string temp = "";
    for(int j = i; j < n; j++){
        temp += s[j];
        if(isPal(temp)){
            int cost = 1 + minPart(j+1, s, n, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int palindromePartitioning(string s) {
    int n = s.size();
//     vector<int> dp(n, -1);
//     return minPart(0, s, n, dp) - 1;
    vector<int> dp(n+1, 0);
    for(int i = n-1; i >= 0; i--){
        int minCost = INT_MAX;
        string temp = "";
        for(int j = i; j < n; j++){
            temp += s[j];
            if(isPal(temp)){
                int cost = 1 + minPart(j+1, s, n, dp);
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}
