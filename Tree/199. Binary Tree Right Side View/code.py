# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def solve(root,lvl):
            if root:
                if(len(res) == lvl):
                    res.append(root.val)
                solve(root.right, lvl+1)
                solve(root.left, lvl+1)
            return

        res = []
        solve(root,0)
        return res
        