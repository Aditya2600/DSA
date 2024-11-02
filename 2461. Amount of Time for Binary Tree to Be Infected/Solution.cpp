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

    TreeNode* first = NULL;
    void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root == NULL) return;
        if(root -> left) parent[root -> left] = root;
        if(root -> right) parent[root -> right] = root;
        makeParent(root -> left, parent);
        makeParent(root -> right, parent);
    }

    void find(TreeNode* root, int start){
        if(root == NULL) return;
        if(root->val == start){
            first = root;
            return;
        }
        find(root -> left, start);
        find(root -> right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);
        unordered_set<TreeNode*> isInfected;
        isInfected.insert(first);
        queue<pair<TreeNode*, int>> q;
        q.push({first, 0});
        int maxLevel = 0;
        while(q.size() > 0){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            int level = p.second;
            maxLevel = max(maxLevel, level);
            TreeNode* temp = p.first;
            if(temp -> left){
                if(isInfected.find(temp -> left) == isInfected.end()){
                    isInfected.insert(temp->left);
                    q.push({temp->left, level+1});
                }
            }
            if(temp -> right){
                if(isInfected.find(temp -> right) == isInfected.end()){
                    isInfected.insert(temp->right);
                    q.push({temp->right, level+1});
                }
            }
            if(parent.find(temp) != parent.end()){
                if(isInfected.find(parent[temp]) == isInfected.end()){
                    isInfected.insert(parent[temp]);
                    q.push({parent[temp], level+1});
                }
            }
        }
        return maxLevel;
    }
};