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
    int goodNodes(TreeNode* root) {
        int count = 0;
        auto dfs = [&](auto&& dfs, TreeNode* node, int maxSoFar) -> void {
            if (!node) return;

            // If the current node's value is >= the maximum value seen so far, it's a good node
            if (node->val >= maxSoFar) {
                count++;
                maxSoFar = node->val; // Update the max value for the deeper paths
            }

            // Traverse left and right children
            dfs(dfs, node->left, maxSoFar);
            dfs(dfs, node->right, maxSoFar);
        };

        dfs(dfs, root, root->val);
        return count;
    }
};
