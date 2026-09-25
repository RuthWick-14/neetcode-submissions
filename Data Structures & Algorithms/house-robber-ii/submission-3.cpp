class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> memo1(nums.size(), -1);
        vector<int> memo2(nums.size(), -1);
        int case1 = robLine(nums, 0, nums.size()-1, memo1);
        int case2 = robLine(nums, 1, nums.size(), memo2);;
        return max(case1, case2);
    }
    int robLine(vector<int>& nums, int start, int end, vector<int>& memo) {
        memo[start] = nums[start];
        memo[start+1] = max(nums[start], nums[start+1]);

        for(int i = start+2; i < end; i++) {
            memo[i] = max(memo[i-1], nums[i] + memo[i-2]);
        }

        return memo[end-1];
    }
};
