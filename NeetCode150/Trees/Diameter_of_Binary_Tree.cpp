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
    int dfs(TreeNode* node, int& diam)
    {
        if(node == nullptr)
        {
            return 0;
        }
        
        int left = dfs(node->left, diam);
        int right = dfs(node->right, diam);
        diam = max(diam, left+right);

        return 1+max(right,left);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        int answer = 0;

        dfs(root, answer);

        return answer;
    }
};
