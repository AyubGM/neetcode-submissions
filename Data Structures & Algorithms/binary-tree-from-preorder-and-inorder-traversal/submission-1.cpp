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
    // preIndex = 0; mid = 1;
    // preorder = [#1,2,3,4], inorder = [2,#1,3,4]
    TreeNode* arrayToTree(vector<int>& preorder, int& preIndex, int start, int end,
                          unordered_map<int, int>& inMap) {
        if (start > end) return nullptr;
        
        int nodeVal = preorder[preIndex];
        int mid = inMap[nodeVal];
        TreeNode* node = new TreeNode(nodeVal);
        preIndex++;

        node->left = arrayToTree(preorder, preIndex, start, mid - 1, inMap);
        node->right = arrayToTree(preorder, preIndex, mid + 1, end, inMap);

        return node;
      
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
