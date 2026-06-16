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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        int currMax = 0;

        auto Dfs = [&](auto&& Dfs, TreeNode* node) -> int{
            
            if (!node) return 0;
            int leftGain = std::max(Dfs(Dfs, node->left), 0);
            int rightGain = std::max(Dfs(Dfs, node->right), 0);

            int currentPathSum = node->val + leftGain + rightGain;
            maxPath = std::max(maxPath, currentPathSum);

            return node->val + std::max(leftGain, rightGain);
            
            //currMax -= node->val;

        };

        Dfs(Dfs, root);

        return maxPath;
    }
};
