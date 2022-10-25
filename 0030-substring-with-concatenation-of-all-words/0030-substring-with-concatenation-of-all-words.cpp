class Solution {
public:
    vector<int> go(int index,map<string,int> &words,string &s,int count){
        int en = index;
        int st = index;
        int n = s.size();
        int wl = words.begin()->first.size();
        vector<int> ans;
        map<string,int> included;
        int countInitial = count;
        while(en < n){
            string temp = s.substr(en,wl);
            if(count > 0){
                if(words.find(temp) != words.end()){
                    while(words[temp] <= included[temp]){
                        string del = s.substr(st,wl);
                        included[del]--;
                        st += wl;
                        count++;
                    }
                    included[temp]++;
                    count--;
                }else{
                    included.clear();
                    en += wl;
                    st = en;
                    count = countInitial;
                    continue;
                }
            }
            
            if(count == 0){
                ans.push_back(st);
                string del = s.substr(st,wl);
                included[del]--;
                st += wl;
                count++;
            }
            en += wl;
        }
        return ans;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words[0].size() > s.size())
            return {};
        int n = s.size();
        int w = words.size();
        int wl = words[0].size();
        vector<int> ans;
        map<string,int> word;
        for(auto x : words)
            word[x]++;
        
        
        for(int i = 0 ; i < wl ; i++){
            auto t = go(i,word,s,w);
            ans.insert(ans.end(),t.begin(),t.end());
        }
        return ans;
    }
};