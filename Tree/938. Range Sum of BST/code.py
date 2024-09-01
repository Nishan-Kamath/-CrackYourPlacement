# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        res = 0
        q = [root]
        while q:
            curr = q.pop()
            if curr:
                if low <= curr.val <= high:
                    res+=curr.val
                if curr.val > low:
                    q.append(curr.left)
                if curr.val < high:
                    q.append(curr.right)
        return res
        