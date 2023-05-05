class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        
        auto calculation = [&](int I){
            for(int i = I ; i < n ; i++){
                for(char j = 'a' ; j < k+'a' ; j++){
                    if(i == I && j >= s[i]) break;
                    int left = max(0,i-2);
                    bool ok = true;
                    for(int k_ = left ; k_ < i ; k_++){
                        if(s[k_] == j) {
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        s[i] = j;
                        break;
                    }
                }
            }
        };
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(char j = s[i] + 1 ; j < k+'a' ; j++){
                int left = max(0,i-2);
                bool ok = true;
                for(int k_ = left ; k_ < i ; k_++){
                    if(s[k_] == j){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    s[i] = j;
                    calculation(i+1);
                    return s;
                }
            }
        }
        return "";
    }
};