class Solution {
public:
int minInsertions(string s) {
int open = 0;
int ans = 0;


    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            open++;
        }
        else {
            if (i + 1 < s.length() && s[i + 1] == ')') {
                if (open > 0) {
                    open--;
                }
                else {
                    ans++;
                }
                i++;
            }
            else {
                if (open > 0) {
                    open--;
                    ans++;
                }
                else {
                    ans += 2;
                }
            }
        }
    }

    return ans + 2 * open;
}


};
