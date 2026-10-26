class Solution {
public:
    vector<vector<int>> memo;
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.assign(n, vector<int>(2, -1));
        return dfs(prices, true, 0);
    }

    int dfs(vector<int>& prices, bool buying, int i) {
        if(i >= prices.size()) return 0;

        int state = buying ? 1: 0;

        if(memo[i][state] != -1) return memo[i][state];

        if(buying) {
            int buy = dfs(prices, false, i+1) - prices[i];
            int skip = dfs(prices, true, i+1);

            memo[i][state] = max(buy, skip);
        }
        else {
            int sell = dfs(prices, true, i+2) + prices[i];
            int skip = dfs(prices, false, i+1);

            memo[i][state] = max(sell, skip);
        }
        return memo[i][state];
    }
};
