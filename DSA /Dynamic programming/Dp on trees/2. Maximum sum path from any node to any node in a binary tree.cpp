class Solution
{
public:
  int solve(TreeNode *root, int &res)
  {
    if (root == NULL)
      return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(root->val, root->val + max(l, r));

    int ans = max(temp, root->val + l + r);

    res = max(res, ans);

    return temp;
  }

  int maxPathSum(TreeNode *root)
  {
    int res = INT_MIN;
    solve(root, res);
    return res;
  }
};