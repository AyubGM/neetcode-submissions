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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        auto Validate = [](auto&& Validate, TreeNode* node, TreeNode* minNode, TreeNode* maxNode) -> bool 
        {
            if (!node) return true;

            if (minNode && node->val <= minNode->val) return false;
            
            if (maxNode && node->val >= maxNode->val) return false;
            
           return Validate(Validate, node->left, minNode, node) && 
                   Validate(Validate, node->right, node, maxNode);
            
        };

        return Validate(Validate, root, nullptr, nullptr);

    }
};
