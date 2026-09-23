class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> dp;

    vector<string> solve(string &s, int start) {
        if (start == s.length()) {
            return {""};
        }

        if (dp.count(start)) {
            return dp[start];
        }

        vector<string> ans;

        for (int end = start; end < s.length(); end++) {

            string word = s.substr(start, end - start + 1);

            if (dict.count(word)) {

                vector<string> remaining = solve(s, end + 1);

                for (string sentence : remaining) {

                    if (sentence == "") {
                        ans.push_back(word);
                    }
                    else {
                        ans.push_back(word + " " + sentence);
                    }
                }
            }
        }

        return dp[start] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        for (string word : wordDict) {
            dict.insert(word);
        }

        return solve(s, 0);
    }
};