class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if(s[i] == s[j]) {
                    if(len == 2 || dp[i+1][j-1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }

        int num = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j]) num++;
            }
        }

        return num;
    }
};
