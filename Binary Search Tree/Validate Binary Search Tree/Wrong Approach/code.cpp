class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            if (node->left)
            {
                q.push(node->left);
                if (node->left->val >= node->val)
                    return false;
            }
            if (node->right)
            {
                q.push(node->right);
                if (node->right->val <= node->val)
                    return false;
            }

            q.pop();
        }

        return true;
    }
};