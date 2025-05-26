class Solution
{
public:
    bool BST(TreeNode *root, long long &prev)
    {
        if (!root)
            return true;

        bool l = BST(root->left, prev);
        if (l == 0)
            return false;

        if (prev >= root->val)
            return false;
        prev = root->val;

        return BST(root->right, prev);
    }

    bool isValidBST(TreeNode *root)
    {
        long long prev = LLONG_MIN; // Use long long in case root->val == INT_MIN
        return BST(root, prev);
    }
};