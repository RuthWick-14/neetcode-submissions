class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        if (nums.size() == 0) return 0;

        if (nums.size() == 1) return nums[0];
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++) {
            memo[i] = max(memo[i-1], nums[i]+memo[i-2]);
        }

        return memo[nums.size()-1];
    }

    
};
