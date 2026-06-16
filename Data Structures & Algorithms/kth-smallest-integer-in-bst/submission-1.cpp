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

        int result = -1;
        
        auto dfs = [&](auto&& dfs, TreeNode* node) -> void {
            // Base case: stop if node is null or we already found our answer
            if (!node || k <= 0) return;

            // 1. Traverse Left
            dfs(dfs, node->left);

            // 2. Process Current Node
            k--; // One more node visited
            if (k == 0) {
                result = node->val; // Found the kth smallest!
                return;
            }

            // 3. Traverse Right
            dfs(dfs, node->right);
        };

        dfs(dfs, root);
        return result;
    }
};
