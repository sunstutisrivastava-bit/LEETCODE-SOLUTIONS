class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string s1="";
        int l=s.size();
        int i,j;
        for(i=0;i<l;i++){
            if(s[i]=='('){
                st.push(s1);
                s1="";
            }
            else if(s[i]==')'){
                reverse(s1.begin(),s1.end());
                s1=st.top()+s1;
                st.pop();
            }
            else{
                s1=s1+s[i];
            }
        }
        return s1;
    }
};