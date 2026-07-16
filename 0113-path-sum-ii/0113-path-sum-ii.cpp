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
    void dfs(TreeNode* root, int targetSum, vector<int>& currentPath, vector<vector<int>>& ans) {
        if (root == nullptr) {
            return;
        }
        currentPath.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && targetSum == root->val) {
            ans.push_back(currentPath);
        } else {
            dfs(root->left, targetSum - root->val, currentPath, ans);
            dfs(root->right, targetSum - root->val, currentPath, ans);
        }
        currentPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currentPath;
        
        dfs(root, targetSum, currentPath, ans);
        
        return ans;
    }
};