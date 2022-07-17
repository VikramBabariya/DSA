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

// palindrome checking pre computation
void preIsPal(string &s, int n, vector<vector<bool>> &isPal){
    for(int k = 0; k < n; k++){
        for(int j = k, i = 0; j < n && i < (n-k); j++, i++){
            if(i == j) isPal[i][j] = true;
            else if(j == i+1) isPal[i][j] = s[i] == s[j];
            else if(s[i] == s[j] && isPal[i+1][j-1]) isPal[i][j] = true;
            else isPal[i][j] = false;
        }
    }
}

int minPart(int i, string &s, int n, vector<vector<bool>> &isPal, vector<int> &dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    for(int j = i; j < n; j++){
        if(isPal[i][j]){
            int cost = 1 + minPart(j+1, s, n, isPal, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}


int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, true));
    preIsPal(s, n, isPal);
    vector<int> dp(n, -1);
    return minPart(0, s, n, isPal, dp) - 1;
}

