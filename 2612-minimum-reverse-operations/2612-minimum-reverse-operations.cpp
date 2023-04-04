class Solution {
public:
    
    pair<int,int> mergeNumbers(vector<int> &v,int n,int k){
        int L = n-1;
        int R = 0;
        for(int i = 0 ; i < v.size() ; i++){
            int l = v[i]-k+1;
            if(l < 0)
                l = abs(l);
            L = min(L,l);
            int r = v[i]+k-1;
            if(r > n-1){
                r = n-1-(r-n+1);
            }
            R = max(R,r);
        }
        return {L,R};
    }
    
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n,-2);
        ans[p] = 0;
        for(auto x : banned){
            ans[x] = -1;
        }
        auto bfs = [&](int src){
            vector<int> Nodes;
            Nodes.push_back(src);
            int level = 0;
            while(!Nodes.empty()){              
                auto Ran = mergeNumbers(Nodes,n,k);
                Nodes.clear();
                int l = Ran.first;
                int r = Ran.second;
                cout<<l<<" "<<r<<"\n";
                for(int i = l ; i <= r ; i += 2){
                    if(ans[i] == -2){
                        ans[i] = level+1;
                        Nodes.push_back(i);
                    }
                }
                level++;
            }
        };
        bfs(p);
        for(int i = 0 ; i < n ; i++){
            if(ans[i] == -2)
                ans[i] = -1;
        }
        return ans;
    }
};