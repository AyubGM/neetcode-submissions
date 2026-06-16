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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        std::string res = "";

        auto Dfs = [&](auto&& Dfs, TreeNode* node) -> void {
            if (!node) {
                res += "X#";
                return;
            }

            res += std::to_string(node->val) + "#";
            Dfs(Dfs, node->left);
            Dfs(Dfs, node->right);
        };

        Dfs(Dfs, root);

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;

        auto Dfs = [&](auto&& Dfs, int& i) -> TreeNode* {
            if (i >= data.length()) return nullptr;
            int j = i;

            while (data[j] != '#') j++;

            std::string token = data.substr(i, j - i);
            
            i = j + 1;

            if (token == "X") {
                return nullptr;
            }
            TreeNode* node = new TreeNode(std::stoi(token));

            node->left = Dfs(Dfs, i);
            node->right = Dfs(Dfs, i);

            return node;
        };

        return Dfs(Dfs, i);
    }
};
