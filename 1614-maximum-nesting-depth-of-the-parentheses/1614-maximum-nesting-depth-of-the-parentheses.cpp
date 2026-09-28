class Solution {
public:
    int maxDepth(string s) {
        stack<char> s1;
        int l=s.size();
        int i,j=0;
        for(i=0;i<l;i++){
            if(s[i]=='('){
                s1.push(s[i]);
                j=s1.size()>j?s1.size():j;
            }
            else if(s[i]==')'){
                s1.pop();
            }
        }
        return j;
    }
};