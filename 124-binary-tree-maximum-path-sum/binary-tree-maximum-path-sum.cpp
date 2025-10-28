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
    int best = INT_MIN;
    int dfs(TreeNode* r){
        if(!r) return 0;
        int L = max(0, dfs(r->left));
        int R = max(0, dfs(r->right));
        best = max(best, r->val + L + R);
        return r->val + max(L,R);
    }
public:
    int maxPathSum(TreeNode* root){ dfs(root); return best; }
};
