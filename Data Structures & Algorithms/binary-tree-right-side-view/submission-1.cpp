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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()) {
            int n = q.size();
            res.push_back(q.front()->val);
            while(n--) {
                TreeNode* node = q.front();
                if(node->right!=NULL)
                    q.push(node->right);
                if(node->left!=NULL)
                    q.push(node->left);
                q.pop();
            }
        }
        return res;
    }
};
//Time complexity: O(N)
//Space complexity: O(1)