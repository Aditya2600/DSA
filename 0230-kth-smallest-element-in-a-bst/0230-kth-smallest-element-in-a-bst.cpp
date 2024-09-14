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
    // Helper function to perform in-order traversal
    void inorder(TreeNode* root, vector<int>& elements) {
        if (!root) return;
        inorder(root->left, elements);  // Traverse left subtree
        elements.push_back(root->val);  // Visit current node
        inorder(root->right, elements); // Traverse right subtree
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> elements;
        inorder(root, elements); // Perform in-order traversal to get sorted elements
        return elements[k - 1];  // Return the k-th smallest element (1-based index)
    }
};
