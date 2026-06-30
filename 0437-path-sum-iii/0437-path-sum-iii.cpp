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
    int count = 0;
    unordered_map<long long, int> mp;
    void solve(TreeNode* root, int targetSum, long long sum){
        if(!root){
            return;
        }
        sum += root -> val;
        if(mp.find(sum - targetSum) != mp.end()){
            count += mp[sum - targetSum];
        }
        mp[sum]++;
        solve(root -> left, targetSum, sum);
        solve(root -> right, targetSum, sum);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        solve(root, targetSum, 0);
        return count;
    }
};