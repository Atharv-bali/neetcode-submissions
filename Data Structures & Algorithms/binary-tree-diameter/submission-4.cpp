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
    int ans = 0;
    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_height = solve(root->left);
        int right_height = solve(root->right);
        ans = max(ans,left_height+right_height);
        return max(left_height,right_height) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
//Time complexity: O(N)
//Space complexity: O(H)