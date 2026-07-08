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
    priority_queue<int> maxHeap;
    void fillHeap(TreeNode* root, int k){
        if(root == nullptr) return;

        maxHeap.push(root->val);

        if(maxHeap.size() > k){
            maxHeap.pop();
        }
        fillHeap(root->left, k);
        fillHeap(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        fillHeap(root, k);
        return maxHeap.top();
    }
};
