class Solution
{
public:
    void inOrder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> ans;

        inOrder(root, ans);

        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i - 1] >= ans[i])
                return false;
        }

        return true;
    }
};