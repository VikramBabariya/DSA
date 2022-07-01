int maximumProfit(vector<int> &prices){
    int profit = 0, mini = prices[0], n = prices.size();
	for(int i = 1; i < n; i++){
		int cost = prices[i] - mini; // sell - buy
		profit = max(profit, cost);
		mini = min(mini, prices[i]);
	}
	return profit;
}
