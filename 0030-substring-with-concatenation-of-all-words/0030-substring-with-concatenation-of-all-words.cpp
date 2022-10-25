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
            //current word that needed to be processed.
            string temp = s.substr(en,wl);
            //if all the required words are not processed yet means count > 0
            if(count > 0){
                //it that word needs to be present in the final window.
                if(words.find(temp) != words.end()){
                    //if the all such words are present in the final window.
                    while(words[temp] <= included[temp]){
                        string del = s.substr(st,wl);
                        included[del]--;
                        st += wl;
                        count++;
                    }
                    //include that word.
                    included[temp]++;
                    count--;
                }else{
                    //it that word need not to be present in the final window so whole window 
                    //should be reevaluated because we found a word that need not to be present.
                    included.clear();
                    en += wl;
                    st = en;
                    count = countInitial;
                    continue;
                }
            }
            
            //if we found a window with all such words that we will update the answer and 
            //shift the window.
            if(count == 0){
                ans.push_back(st);
                string del = s.substr(st,wl);
                included[del]--;
                st += wl;
                count++;
            }
            //pass the control to the next word.
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