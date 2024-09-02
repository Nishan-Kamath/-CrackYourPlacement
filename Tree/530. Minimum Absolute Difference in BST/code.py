# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getMinimumDifference(self, root):
        def traverse(node,low,high):
            if not node:
                return high-low
            left = traverse(node.left, low ,node.val)
            right = traverse(node.right, node.val, high)
            return min(left,right)

        return traverse(root, float('-inf'),float('inf'))
        