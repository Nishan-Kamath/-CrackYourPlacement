"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return root
        if root.left:
            left, right = root.left, root.right
            self.connect(left)
            self.connect(right)
            while left:
                left.next = right
                left, right = left.right, right.left
                
        return root
        