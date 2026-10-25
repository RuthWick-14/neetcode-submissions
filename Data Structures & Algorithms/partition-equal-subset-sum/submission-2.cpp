class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum%2 != 0) return false;
        int target = sum/2;

        dp.assign(nums.size()+1, vector<int>(target+1, 0));
        for(int i = 0; i <= nums.size(); i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 1; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }
        return dp[nums.size()][target];
    }
};
