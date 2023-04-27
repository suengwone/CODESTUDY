class Solution {
public:
    TreeNode* swapNode(TreeNode* node)
    {
        TreeNode* tempRight = node->right;
        TreeNode* tempLeft = node->left;
        node->right = tempRight;
        node->left = tempLeft;
        return node;
    }

    TreeNode* invertTree(TreeNode* root) 
    {
        queue<TreeNode*> remains;

        remains.push(root);

        while(remains.empty() != true)
        {
            TreeNode* temp = remains.front();
            remains.pop();

            if(temp == nullptr) continue;

            remains.push(temp->right);
            remains.push(temp->left);
            
            TreeNode* tempRight = temp->right;
            TreeNode* tempLeft = temp->left;
            temp->right = tempLeft;
            temp->left = tempRight;
        }

        return root;
    }
};
