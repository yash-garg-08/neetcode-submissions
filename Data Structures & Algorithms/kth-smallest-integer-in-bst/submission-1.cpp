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
    // Max heap to store the k smallest elements encountered so far.
    // The largest among these k elements will always be at the top.
    priority_queue<int> maxHeap;

    // Traverses the entire tree and maintains a max heap of size k.
    void fillHeap(TreeNode* root, int k) {
        // Base case: reached the end of a branch.
        if (root == nullptr) return;

        // Add the current node's value to the heap.
        maxHeap.push(root->val);

        // If the heap size exceeds k, remove the largest element.
        // This ensures only the k smallest elements remain in the heap.
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }

        // Recursively process the left subtree.
        fillHeap(root->left, k);

        // Recursively process the right subtree.
        fillHeap(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        // Populate the heap with the k smallest elements.
        fillHeap(root, k);

        // The top of the max heap is the kth smallest element.
        return maxHeap.top();
    }
};