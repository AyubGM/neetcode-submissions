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
    int maxD = 0;
    int Dfs(TreeNode* node) {
        if (!node) return 0;

        int left = Dfs(node->left);
        int right = Dfs(node->right);

        maxD = max(maxD ,left + right);

        return 1 + max(left, right);

    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        Dfs(root);

        return maxD;
    }
};
