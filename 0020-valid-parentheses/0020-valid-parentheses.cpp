class Solution {
public:
    bool isValid(string s) {
        stack<char> a;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                a.push(s[i]);
            }
            else {
                if (a.empty())
                    return false;

                if (s[i] == ')' && a.top() == '(') {
                    a.pop();
                }
                else if (s[i] == '}' && a.top() == '{') {
                    a.pop();
                }
                else if (s[i] == ']' && a.top() == '[') {
                    a.pop();
                }
                else {
                    return false;
                }
            }
        }

        return a.empty();
    }
};