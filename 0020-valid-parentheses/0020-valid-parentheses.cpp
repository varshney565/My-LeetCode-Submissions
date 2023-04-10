class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        auto check = [&](char a,char b){
            if(a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}') return true;
            return false;
        };
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                if(check(top,s[i])){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};