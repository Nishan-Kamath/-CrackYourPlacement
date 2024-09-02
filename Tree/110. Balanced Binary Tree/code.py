# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        return self.Height(root)>=0
    
    def Height(self,root):
        if root is None:
            return 0
        left, right = self.Height(root.left), self.Height(root.right)
        if left < 0 or right < 0 or abs(left - right) > 1:
            return -1

        return max(left,right)+1
        