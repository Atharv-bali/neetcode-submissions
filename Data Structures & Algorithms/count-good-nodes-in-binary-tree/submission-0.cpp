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
    int solve(TreeNode* root, int currMax) {
        if(root == NULL)
            return 0;
        int rootAns = 0;
        if(root->val >= currMax) {
            rootAns = 1;
            currMax = root->val;
        }
        int left = solve(root->left,currMax);
        int right = solve(root->right,currMax);
        return left+right+rootAns;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
//Time complexity: O(N)
//Space complexity: O(1)