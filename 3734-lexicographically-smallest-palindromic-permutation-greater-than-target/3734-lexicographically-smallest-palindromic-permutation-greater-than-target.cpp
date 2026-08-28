class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        int halfLen = n / 2;

        // Characters available for left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        // -------------------------------------------------
        // STEP 1:
        // Try to make left half EXACTLY equal to
        // target's first half.
        // -------------------------------------------------

        vector<int> freq = half;
        string left;
        bool canEqual = true;

        for (int i = 0; i < halfLen; i++) {
            int c = target[i] - 'a';

            if (freq[c] == 0) {
                canEqual = false;
                break;
            }

            left += target[i];
            freq[c]--;
        }

        if (canEqual) {
            string ans = left;

            if (n % 2)
                ans += middle;

            string right = left;
            reverse(right.begin(), right.end());

            ans += right;

            // Exact left half may already give answer
            if (ans > target)
                return ans;
        }

        // -------------------------------------------------
        // STEP 2:
        // Make left half GREATER than target's first half.
        //
        // Change the rightmost possible position.
        // -------------------------------------------------

        for (int pos = halfLen - 1; pos >= 0; pos--) {

            freq = half;
            left = "";
            bool possible = true;

            // Match target before pos
            for (int i = 0; i < pos; i++) {

                int c = target[i] - 'a';

                if (freq[c] == 0) {
                    possible = false;
                    break;
                }

                left += target[i];
                freq[c]--;
            }

            if (!possible)
                continue;

            // At pos, choose the smallest available
            // character greater than target[pos]
            int need = target[pos] - 'a';

            for (int c = need + 1; c < 26; c++) {

                if (freq[c] == 0)
                    continue;

                string L = left;
                L += char('a' + c);

                freq[c]--;

                // Fill remaining positions as small as possible
                for (int x = 0; x < 26; x++) {
                    while (freq[x] > 0) {
                        L += char('a' + x);
                        freq[x]--;
                    }
                }

                // Build palindrome
                string ans = L;

                if (n % 2)
                    ans += middle;

                string R = L;
                reverse(R.begin(), R.end());

                ans += R;

                return ans;
            }
        }

        return "";
    }
};