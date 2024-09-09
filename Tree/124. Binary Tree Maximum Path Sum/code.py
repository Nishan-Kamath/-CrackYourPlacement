# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right



class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        ans = [None]
        
        def check(node):
      
            if not node:
                return 0
            
            l = max(0,check(node.left))
            r = max(0, check(node.right))

            ans[0] = max(ans[0], l + node.val + r)
            return node.val + max(l,r)

        check(root)
        return ans[0]
        