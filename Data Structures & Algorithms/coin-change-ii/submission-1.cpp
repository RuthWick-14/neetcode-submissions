class Solution {
public:
    // vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> memo(n+1, vector<int>(amount+1, -1));
        return dfs(0, coins, amount, memo);
    }

    int dfs(int i, vector<int>& coins, int amount, vector<vector<int>>& memo) {
        if(amount == 0) return 1;
        if(i >= coins.size()) return 0;

        if(memo[i][amount] != -1) return memo[i][amount];

        if(amount < coins[i]) {
            return memo[i][amount] = 0;
        }

        int res = 0;
        if(amount >= coins[i]) {
            int skip = dfs(i+1, coins, amount, memo);
            int used = dfs(i, coins, amount-coins[i], memo);

            memo[i][amount] = skip + used;
        }
        return memo[i][amount];
    }
};
