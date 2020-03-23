/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res=0;
    int maxPathSum(TreeNode *root) {
        res=root->val;
        dfs(root);
        return res;
    }   
    int dfs(TreeNode *t){
        if(!t)return 0;
        int l=dfs(t->left),r=dfs(t->right);
        res=max(t->val+l+r,res);
        return max(max(max(l+t->val,r+t->val),t->val),0);
    }
};