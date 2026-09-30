class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int l=seq.size();
        int i,j,m=0;
        vector<int> a;
        stack<char> s;

        for(i=0;i<l;i++){
            if(seq[i]=='('){
                s.push(seq[i]);

                if((s.size()%2)==0){
                    a.push_back(1);
                }
                else{
                    a.push_back(0);
                }
            }
            else{
                if((s.size()%2)==0){
                    a.push_back(1);
                }
                else{
                    a.push_back(0);
                }

                s.pop();
            }
        }

        return a;
    }
};