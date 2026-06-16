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
    bool isBalanced(TreeNode* root) {

        auto checkHeight = [](this auto&& self ,TreeNode* root) -> int
        {
            if(!root) return 0;

            int leftH = self(root->left);
            if(leftH == -1) return -1;

            int rightH = self(root->right);
            if(rightH == -1) return -1;

            if (std::abs(leftH - rightH) > 1)
            {
                return -1;
            }

            return 1 + std::max(leftH, rightH);
        };



        return checkHeight(root) != -1;
    }
};
