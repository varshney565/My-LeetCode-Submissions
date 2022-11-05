class Solution {
public:

    int dfs(TreeNode* root,map<int,int>&height,map<int,vector<int>> &levels,map<int,int> &LevelNumber,int level){
        if(root == NULL) return 0;
        int lh = dfs(root->left,height,levels,LevelNumber,level+1);
        int rh = dfs(root->right,height,levels,LevelNumber,level+1);
        int ch = max(lh,rh)+1;
        height[root->val] = ch;
        LevelNumber[root->val] = level;
        levels[level].push_back(ch);
        return ch;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<int,int> height;
        map<int,vector<int>> levels;
        map<int,int> LevelNumber;
        vector<int> ans;
        int heightOfTree = dfs(root,height,levels,LevelNumber,0);
        for(auto &[a,x] : levels) sort(x.begin(),x.end(),greater<int>());
        for(auto x : queries){
            int currLevel = LevelNumber[x];
            if(levels[currLevel].size() == 1){
                ans.push_back(heightOfTree-height[x]-1);
            }else{
                int first = levels[currLevel][0];
                int second = levels[currLevel][1];
                if(height[x] < first){
                    ans.push_back(heightOfTree-1);
                }else{
                    ans.push_back(heightOfTree-(first-second)-1);
                }
            }
        }
        return ans;
    }
};