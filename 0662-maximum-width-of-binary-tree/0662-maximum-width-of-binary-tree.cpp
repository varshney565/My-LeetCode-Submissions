/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
unsigned long long max(const unsigned long long &a,const unsigned long long &b){
    return ((a < b)?b:a);
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> CurrentLevel;
        queue<pair<TreeNode*,unsigned long long>> NextLevel;
        CurrentLevel.push({root,0});
        unsigned long long min_ = ULLONG_MAX;
        unsigned long long max_ = 0;
        int ans = 0;
        unsigned long long mmin = 0;
        while(!CurrentLevel.empty()){
            auto f = CurrentLevel.front();
            CurrentLevel.pop();
            if(min_ == INT_MAX){
                mmin = f.second;
            }
            f.second -= mmin;
            min_ = min(min_,f.second);
            max_ = max(max_,f.second);
            if(f.first->left){
                NextLevel.push({f.first->left,2*f.second+1});
            }
            if(f.first->right){
                NextLevel.push({f.first->right,2*f.second+2});
            }
            if(CurrentLevel.empty()){
                swap(CurrentLevel,NextLevel);
                ans = max(ans,max_-min_+1);
                min_ = ULLONG_MAX;
                max_ = 0;
            }
        }
        return ans;
    }
};