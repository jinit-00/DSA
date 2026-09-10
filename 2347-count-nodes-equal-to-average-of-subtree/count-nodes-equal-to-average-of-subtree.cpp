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
    int answer = 0;

    int find(TreeNode* root,int &count)
    {
        if(root == nullptr)
        return 0;
        count++;
        return find(root->left,count) + find(root->right,count) + root->val;
    }
    void solve(TreeNode* root)
    {
        if(root == nullptr)
        return;

        int count = 0;
        int val = find(root,count);
        
        if(root->val == (val)/count)
            answer++;
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return answer;
    }
};