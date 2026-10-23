class Solution {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        dp.assign(n, 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
