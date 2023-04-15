class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n = path.size();
        int i = 1;
        path += '/';
        while(i < n){
            string t = "";
            while(path[i] != '/') {
                t += path[i];
                i++;
            }
            i++;
            if(t == "."){
                continue;
            }else if(t == ".."){
                if(!s.empty())
                    s.pop();
            }else if(t.size() > 0){
                s.push(t);
            }
        }
        string ans = "";
        if(s.empty()) return "/";
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans;
    }
};