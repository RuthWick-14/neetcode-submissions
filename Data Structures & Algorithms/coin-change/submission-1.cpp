class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, -1);
        int ans = dfs(0, coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
    int dfs(int start, vector<int>& coins, int target) {
        if(start == target) return 0;
        if(dp[start] != -1) return dp[start];
        int ans = INT_MAX;

        for(int x : coins) {
            if(x <= target-start) {
                int result = dfs(start+x, coins, target);
                if(result != INT_MAX) {
                    ans = min(ans, 1 + result);
                }
            }
        }
        dp[start] = ans;
        return dp[start];
    }
};
