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

        std::priority_queue<int> pq;

        auto dfs = [&](auto&& dfs,TreeNode* root) -> void {

            if (!root) return;

            dfs(dfs,root->left);
            pq.push(root->val);
            
            if(pq.size() > k)
            pq.pop();

            
            
            dfs(dfs,root->right);
        };
        dfs(dfs, root);
        return pq.top();
    }
};
