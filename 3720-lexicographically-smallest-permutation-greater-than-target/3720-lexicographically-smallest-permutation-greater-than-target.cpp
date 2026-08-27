class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";

        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Case 1: We can keep target[i] same
            if (freq[x] > 0) {
                prefix += target[i];
                freq[x]--;
                continue;
            }

            // Case 2: We cannot keep target[i].
            // Try to make the answer greater at position i.
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = prefix;
                    ans += char('a' + c);

                    freq[c]--;

                    // Remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        ans += string(freq[j], char('a' + j));
                    }

                    return ans;
                }
            }

            // Case 3: Cannot make position i greater.
            // Backtrack to an earlier position.
            //
            // Restore target[i-1], target[i-2], ...
            // and try increasing one of them.

            for (int j = i - 1; j >= 0; j--) {

                // Restore target[j]
                freq[target[j] - 'a']++;

                int current = target[j] - 'a';

                // Try smallest character > target[j]
                for (int c = current + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = target.substr(0, j);

                        ans += char('a' + c);

                        freq[c]--;

                        // Put all remaining characters smallest-first
                        for (int k = 0; k < 26; k++) {
                            ans += string(freq[k], char('a' + k));
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // We successfully constructed target itself.
        // But answer must be STRICTLY greater.
        //
        // So backtrack from the last position.

        for (int j = n - 1; j >= 0; j--) {

            // Restore target[j]
            freq[target[j] - 'a']++;

            int current = target[j] - 'a';

            // Find smallest character greater than target[j]
            for (int c = current + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = target.substr(0, j);

                    ans += char('a' + c);

                    freq[c]--;

                    // Remaining characters sorted
                    for (int k = 0; k < 26; k++) {
                        ans += string(freq[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};