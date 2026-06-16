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

       auto Dfs = [&](auto&& Dfs, TreeNode* node, int maxSoFar) -> void
       {
          
          maxSoFar = std::max(node->val, maxSoFar);

          if(node->val >= maxSoFar)
          count++;

         if (node->left) Dfs(Dfs ,node->left, maxSoFar);
         if (node->right) Dfs(Dfs ,node->right, maxSoFar);
       };

       Dfs(Dfs ,root, root->val);

       return count;


    }
};
