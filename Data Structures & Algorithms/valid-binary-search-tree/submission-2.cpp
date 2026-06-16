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

        auto validate = [](auto&& validate, TreeNode* root, long long minVal,
                           long long maxVal) -> bool {
            if (!root) return true;

            if(root->val <= minVal || root->val >= maxVal)
            {
                return false;
            }

            return validate(validate, root->left, minVal, root->val) &&
                   validate(validate, root->right, root->val, maxVal);
        };

        return validate(validate, root, LLONG_MIN, LLONG_MAX);
    }
};
