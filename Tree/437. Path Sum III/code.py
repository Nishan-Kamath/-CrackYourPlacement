# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    cnt = 0
    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: int
        """
        self.cnt = 0
        
        def dfs(node, currentSum):
            if not node:
                return
            
            currentSum += node.val
            if currentSum == targetSum:
                self.cnt += 1
            
            dfs(node.left, currentSum)
            dfs(node.right, currentSum)
        
        def findPaths(node):
            if not node:
                return
                
            dfs(node, 0)

            findPaths(node.left)
            findPaths(node.right)
        
        findPaths(root)
        return self.cnt
        