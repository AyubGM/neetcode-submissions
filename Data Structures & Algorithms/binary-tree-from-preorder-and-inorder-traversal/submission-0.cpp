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
    TreeNode* arrayToTree(vector<int>& preorder, int& preIndex, int start, int end,
                          unordered_map<int, int>& inMap) {
        if (start > end) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];

        root->left = arrayToTree(preorder, preIndex, start, inIndex - 1, inMap);
        root->right = arrayToTree(preorder, preIndex, inIndex + 1, end, inMap);

        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        std::unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        int preIndex = 0;
        return arrayToTree(preorder, preIndex, 0, inorder.size() - 1, inMap);
    }
};
