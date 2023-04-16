class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> PendingNodes;
        PendingNodes.push({root,NULL});
        int sum = root->val;
        map<TreeNode*,int> t;
        t[0] += root->val;
        int level = 0;
        while(!PendingNodes.empty()){
            int size = PendingNodes.size();
            map<TreeNode*,int> tmp;
            int tsum = 0;
            while(size-->0){
                auto f = PendingNodes.front();
                PendingNodes.pop();
                
                int psum = t[f.second];
                if(psum == sum){
                    f.first->val = 0;
                }else{
                    f.first->val = sum-psum;
                }
                
                if(f.first->left){
                    PendingNodes.push({f.first->left,f.first});
                    tmp[f.first] += f.first->left->val;
                    tsum += f.first->left->val;
                }
                if(f.first->right){
                    PendingNodes.push({f.first->right,f.first});
                    tmp[f.first] += f.first->right->val;
                    tsum += f.first->right->val;
                }
            }
            t = tmp;
            sum = tsum;
            level++;
        }
        return root;
    }
};