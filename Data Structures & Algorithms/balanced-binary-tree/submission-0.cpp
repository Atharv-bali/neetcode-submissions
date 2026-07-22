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
    bool ans=true;
    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_height = solve(root->left);
        int right_height = solve(root->right);
        if(abs(left_height-right_height)>1)
            ans = false;
        return 1+max(left_height,right_height);
    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return ans;
    }
};
//Time complexity: O(N)
//Space complexity: O(H)