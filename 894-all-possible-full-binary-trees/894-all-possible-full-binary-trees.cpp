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
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0)
            return {};
        if(n == 1){
            return {new TreeNode()};
        }
        n--;
        vector<TreeNode*> ans;
        for(int leftCount = 1 ; leftCount < n ; leftCount += 2){
            vector<TreeNode*> left = allPossibleFBT(leftCount);
            vector<TreeNode*> right = allPossibleFBT(n-leftCount);
            for(int i = 0 ; i < left.size() ; i++){
                for(int j = 0 ; j < right.size() ; j++){
                    TreeNode* root = new TreeNode();
                    root->left = left[i];
                    root->right = right[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};