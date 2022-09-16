int maxProf(int i, int cap, int weight[], int profit[], vector<vector<int>> &dp){
        if(i == 0){
            if(weight[i] <= cap) return profit[0];
            else return 0;
        }
        
        if(dp[i][cap] != -1) return dp[i][cap];
        
        int notTake = maxProf(i-1, cap, weight, profit, dp);
        int take = -1e7;
        if(weight[i] <= cap){
            take = profit[i] + maxProf(i-1, cap - weight[i], weight, profit, dp);
        }
        return dp[i][cap] = max(notTake, take);
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int>(W+1, -1)); 
       return maxProf(n-1, W, wt, val, dp);
    }
