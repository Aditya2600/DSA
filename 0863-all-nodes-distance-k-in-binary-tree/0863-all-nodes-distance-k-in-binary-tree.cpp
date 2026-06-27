/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void BFS(TreeNode* target,int k, vector<int>& result){
        queue<TreeNode*> que;
        que.push(target);

        unordered_set<int> vis;
        vis.insert(target -> val);

        while(!que.empty()){
            int n = que.size();
            if(k == 0){
                break;
            }
            while(n--){
                TreeNode* curr = que.front();
                que.pop();

                if(curr -> left != NULL && !vis.count(curr -> left -> val)){
                    que.push(curr -> left);
                    vis.insert(curr -> left -> val);
                }
                if(curr -> right != NULL && !vis.count(curr -> right -> val)){
                    que.push(curr -> right);
                    vis.insert(curr -> right -> val);
                }
                if(parent.count(curr) && !vis.count(parent[curr] -> val)){
                    que.push(parent[curr]);
                    vis.insert(parent[curr] -> val);
                }
            }
            k--;
        }
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }
    void inOrder(TreeNode* root){
        if(!root){
            return;
        }
        if(root -> left){
            parent[root -> left] = root;       
        }
        inOrder(root -> left);
        if(root -> right){
            parent[root -> right] = root;
        }
        inOrder(root -> right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        inOrder(root);

        BFS(target,k, result);
        return result;
    }
};