class Solution {
public:
    string removeStars(string s) {
        int l = s.size();
        int i;
        stack<char> a;

        for(i = 0; i < l; i++) {
            if(s[i] == '*') {
                a.pop();
            }
            else {
                a.push(s[i]);
            }
        }

        string s1 = "";

        while(!a.empty()) {
            s1 += a.top();
            a.pop();
        }

        reverse(s1.begin(), s1.end());

        return s1;
    }
};