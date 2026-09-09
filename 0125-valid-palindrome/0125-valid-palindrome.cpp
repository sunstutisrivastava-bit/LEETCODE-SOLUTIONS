class Solution {
public:
    bool isPalindrome(string s) {
       int i,j,c=0,k=0;
       i=0;
       j=s.size()-1;
       if(j+1==1){
        return true;
       }
       while(i<j){
        if(s[i]>=65&&s[i]<=90) s[i]=tolower(s[i]);
        else if(!((s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57))){
            i++;
            continue;
        }
        if(s[j]>=65&&s[j]<=90) s[j]=tolower(s[j]);
        else if(!((s[j]>=97&&s[j]<=122)||(s[j]>=48&&s[j]<=57))) {
            j--;
            continue;
        }
        if(s[i]==s[j]){
            c++;
            
        } 
        k++; 
        i++;
        j--;     

       }
       if(c==k){
        return true;
       }
       else{
        return false;
       }
    }
};