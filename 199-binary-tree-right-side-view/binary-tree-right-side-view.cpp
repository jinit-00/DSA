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
        vector<int> answer;
        if(root == nullptr)
        return answer;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int value = 0;
            while(n--)
            {
                TreeNode* node = q.front();
                value = node->val; 
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            answer.push_back(value);
        }
    return answer;
    }
};