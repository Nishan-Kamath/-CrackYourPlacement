# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        def helper(node,level):
            if not node:
                return
            
            if(len(levels) == level):
                levels.append([])
            
            if level%2 == 0:
                levels[level].append(node.val)
            else:
                levels[level].insert(0,node.val)

            helper(node.left, level+1)
            helper(node.right, level+1)

        helper(root,0)
        return levels
        