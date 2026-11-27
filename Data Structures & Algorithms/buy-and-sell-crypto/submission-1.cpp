class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int mini = INT_MAX;
        int n = prices.size();

        for(int i=0; i<n; i++){
            mini = min(mini, prices[i]);
            max_profit = max(max_profit, prices[i] - mini);
        }

        return max_profit;
    }
};
