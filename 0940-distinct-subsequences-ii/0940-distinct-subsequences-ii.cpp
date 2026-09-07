class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        // dp[i] = number of distinct subsequences
        // using first i characters, including empty subsequence
        vector<long long> dp(s.size() + 1);

        // last[c] = last position where character c appeared
        vector<int> last(26, -1);

        dp[0] = 1;  // empty subsequence

        for (int i = 1; i <= s.size(); i++) {
            char ch = s[i - 1];

            // Take or don't take current character
            dp[i] = (2 * dp[i - 1]) % MOD;

            int c = ch - 'a';

            // Remove duplicate subsequences
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }

            last[c] = i;
        }

        // Remove empty subsequence
        return (dp[s.size()] - 1 + MOD) % MOD;
    }
};