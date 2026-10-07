class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;
        unordered_set<string> visited;

        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            int balance = 0;
            bool valid = true;

            // Check whether current string is valid
            for (char ch : curr) {

                if (ch == '(') {
                    balance++;
                }
                else if (ch == ')') {

                    balance--;

                    if (balance < 0) {
                        valid = false;
                        break;
                    }
                }
            }

            if (balance != 0) {
                valid = false;
            }

            if (valid) {
                ans.push_back(curr);
                found = true;
            }

            // If valid strings are already found,
            // don't remove any more characters.
            if (found) {
                continue;
            }

            // Generate strings by removing one parenthesis
            for (int i = 0; i < curr.length(); i++) {

                if (curr[i] != '(' && curr[i] != ')') {
                    continue;
                }

                string next = curr.substr(0, i) +
                              curr.substr(i + 1);

                if (visited.find(next) == visited.end()) {

                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};