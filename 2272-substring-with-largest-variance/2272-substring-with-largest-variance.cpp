class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        int ans = 0;
        set<char> Dict;
        for(auto x : s){
            Dict.insert(x);
        }
        for(char Max = 'a' ; Max <= 'z' ; Max++){
            if(Dict.find(Max) == Dict.end()) continue;
            for(char Min = 'a' ; Min <= 'z' ; Min++){
                if(Dict.find(Min) == Dict.end()) continue;
                int cnt = 0;
                bool second = false;
                for(int i = 0 ; i < n ; i++){
                    if(s[i] == Min){
                        cnt--;
                        second = true;
                    }else if(s[i] == Max){
                        cnt++;
                    }
                    if(second)
                        ans = max(ans,cnt);
                    else
                        ans = max(ans,cnt-1);
                    if(cnt < 0){
                        cnt = 0;
                        second = false;
                    }
                }
            }
        }
        return ans;
    }
};