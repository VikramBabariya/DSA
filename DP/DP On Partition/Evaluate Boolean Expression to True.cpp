#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long

ll Ways(int i, int j, bool isTrue, string & exp, vector<vector<vector<ll>>> &dp){
    if(i > j) return 0;
    if(i == j){
        if(isTrue) return exp[i] == 'T';
        return exp[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    ll totalWays = 0;
    for(int k = i+1; k <= j-1; k+=2){
        ll lt = Ways(i, k-1, true, exp, dp);
        ll lf = Ways(i, k-1, false, exp, dp);
        ll rt = Ways(k+1, j, true, exp, dp);
        ll rf = Ways(k+1, j, false, exp, dp);
        
        if(exp[k] == '|'){
            if(isTrue) 
                totalWays = (totalWays + (lt * rt)%MOD + (lt * rf)%MOD + (lf * rt)%MOD)%MOD;
            else totalWays = (totalWays + (lf * rf)%MOD)%MOD;
        }else if(exp[k] == '&'){
            if(isTrue) totalWays = (totalWays + (lt * rt)%MOD)%MOD;
            else totalWays = (totalWays + (lf * rf)%MOD + (lt * rf)%MOD + (lf * rt)%MOD)%MOD;
        }else if(exp[k] == '^'){
            if(isTrue) totalWays = (totalWays + (lt * rf)%MOD + (lf * rt)%MOD)%MOD;
            else totalWays = (totalWays + (lf * rf)%MOD + (lt * rt)%MOD)%MOD;
        }
    }
    return dp[i][j][isTrue] = totalWays%MOD;
}

int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return Ways(0, n-1, true, exp, dp);
}
