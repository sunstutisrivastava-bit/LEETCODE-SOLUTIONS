class Solution {
public:
    int longestValidParentheses(string s) {
        int l = s.size();
        int i, ans = 0;

        stack<char> s1;
        stack<int> s2;

        s2.push(-1);

        for(i = 0; i < l; i++) {

            if(s[i] == '(') {
                s1.push(s[i]);
                s2.push(i);
            }

            else if(s[i] == ')') {

                if(!s1.empty()) {
                    s1.pop();
                    s2.pop();

                    ans = max(ans, i - s2.top());
                }
                else {
                    s2.pop();
                    s2.push(i);
                }
            }
        }

        return ans;
    }
};