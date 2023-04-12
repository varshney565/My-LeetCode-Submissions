class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> GivenWords;
        for(auto x : wordList) GivenWords.insert(x);
        map<string,vector<string>> parent;
        queue<string> PendingNodes;
        PendingNodes.push(beginWord);
        vector<vector<string>> ans;
        set<string> todo;
        todo.insert(beginWord);
        int level = 0;
        while(!PendingNodes.empty()){
            int size = PendingNodes.size();
            bool ok = false;
            for(auto x : todo) GivenWords.erase(x);
            todo.clear();
            while(size-->0){
                string t = PendingNodes.front();
                PendingNodes.pop();
                if(t == endWord){
                    ok = true;
                }
                for(int i = 0 ; i < t.size() ; i++){
                    string yes = t;
                    for(char j = 'a' ; j <= 'z' ; j++){
                        yes[i] = j;
                        if(GivenWords.find(yes) != GivenWords.end()){
                            if(todo.find(yes) == todo.end())
                                PendingNodes.push(yes);
                            parent[yes].push_back(t);
                            todo.insert(yes);
                        }
                    }
                }
            }
            if(ok)
                break;
            level++;
        }
        
        vector<string> temp;
        function<void(string)> dfs = [&](string st){
            if(st == beginWord) {
                vector<string> p = temp;
                p.push_back(st);
                reverse(p.begin(),p.end());
                ans.push_back(p);
                return;
            }
            temp.push_back(st);
            for(auto x : parent[st]){
                dfs(x);
            }
            temp.pop_back();
        };
        dfs(endWord);
        return ans;
    }
};