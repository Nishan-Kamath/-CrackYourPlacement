# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    head = None
    def flatten(self, root):
        def revPreorder(node):
            if node.right:
                revPreorder(node.right)
            if node.left:
                revPreorder(node.left)
            node.left, node.right, self.head = None, self.head, node
        
        if root:
            revPreorder(root)
        