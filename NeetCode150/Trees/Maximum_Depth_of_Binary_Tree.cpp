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
    int max_depth;
    void dfs(TreeNode* node, int depth)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            if(max_depth < depth)
            {
                max_depth = depth;
            }
        }
        else
        {
            if(node->left != nullptr)
            {
                dfs(node->left, depth + 1);
            }
            if(node->right != nullptr)
            {
                dfs(node->right, depth + 1);
            }
        }
    }

    int maxDepth(TreeNode* root)
    {
        max_depth = 0;

        if(root != nullptr)
        {
            dfs(root, 1);
        }

        return max_depth;
    }
};
