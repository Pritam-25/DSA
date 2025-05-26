class Solution
{
public:
    void inOrder(TreeNode *root, int &ans, int &k)
    {
        if (!root || k == 0)
            return;

        inOrder(root->left, ans, k);
        if (k > 0)
        {
            ans = root->val;
            k--;
        }
        inOrder(root->right, ans, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
        inOrder(root, ans, k);
        return ans;
    }
};