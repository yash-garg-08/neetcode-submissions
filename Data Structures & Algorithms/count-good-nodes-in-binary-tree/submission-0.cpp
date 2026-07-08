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
    int count;
    void getGood(TreeNode* root, int maxi){
        if(root == nullptr){
            return;
        }

        if(root->val >= maxi){
            count++;
            maxi = root->val;
        }

        getGood(root->left, maxi);
        getGood(root->right, maxi);

    }
    int goodNodes(TreeNode* root) {
        int maxi = root->val;
        count = 0;
        getGood(root, maxi);
        return count;
    }
};
