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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> pQ;
        std::queue<TreeNode*> qQ;

        pQ.push(p);
        qQ.push(q);

        while (!pQ.empty() || !qQ.empty())
        {
            TreeNode* pLevel = pQ.front();
            pQ.pop();

            TreeNode* qLevel = qQ.front();
            qQ.pop();

            if (!pLevel && !qLevel) continue;

            if (!pLevel || !qLevel) return false;

            if (pLevel->val != qLevel->val) return false;

            pQ.push(pLevel->left);
            pQ.push(pLevel->right);

            qQ.push(qLevel->left);
            qQ.push(qLevel->right);
        }

        return true;
    }
};
