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
    int kthSmallest(TreeNode* root, int k) {
        int smallest = INT_MAX;
        auto Dfs = [&](auto&& Dfs, TreeNode* node) {
            
            if (!node) return;

            Dfs(Dfs, node->left);
            
            k--;
            if (k == 0) {
                smallest = node->val;
            }

            Dfs(Dfs, node->right);
        };

        Dfs(Dfs, root);

        return smallest;
    }
};
