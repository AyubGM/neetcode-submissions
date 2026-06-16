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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) return res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int levelSize = q.size();
            std::vector<int> currentLevel;


            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val);

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

           res.push_back(currentLevel);
        }

        return res;
    }
};
