# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode | None) -> int:
        def solve(root: TreeNode):
            if root is None:
                return (0, 0)
            
            left = solve(root.left)
            right = solve(root.right)

            take = root.val + left[1] + right[1]
            skip = max(left[1], left[0]) + max(right[0], right[1])

            return (take, skip)
        
        take, skip = solve(root)
        return max(take, skip)

    

        