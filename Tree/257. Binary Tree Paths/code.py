# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        res = []
        def dfs(root,ans=""):
            if not root:
                return
            if not root.left and not root.right:
                res.append(ans+str(root.val))

            dfs(root.left,ans+str(root.val)+'->')
            dfs(root.right, ans+str(root.val)+'->')
        
        dfs(root,"")
        return res
        