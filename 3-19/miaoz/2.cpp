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
    vector<vector<int> > res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        dfs(root,sum,tmp);
        return res;
    }
    void dfs(TreeNode* t,int sum,vector<int> vec){
        if(t==NULL)return;
        sum-=t->val;
        vec.push_back(t->val);
        if(sum==0&&t->left==NULL&&t->right==NULL){
            res.push_back(vec);
            return;
        }
        dfs(t->left,sum,vec);
        dfs(t->right,sum,vec);
    }
};