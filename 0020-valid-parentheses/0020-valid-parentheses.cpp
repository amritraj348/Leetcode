class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
            int x=st.top();
            st.pop();

            if(x=='('&&s[i]==')'||x=='['&&s[i]==']'||x=='{'&&s[i]=='}'){
                continue;
            }
            else{
                return false;
            }
        }
        }
        return st.empty();
    }
};