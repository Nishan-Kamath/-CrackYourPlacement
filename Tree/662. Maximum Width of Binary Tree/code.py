# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        queue = deque([(root,1)])
        max_width = 0
        while(queue):
            level_width = queue[-1][1] - queue[0][1] + 1
            max_width = max(max_width, level_width)
            level_size = len(queue)

            for _ in range(level_size):
                curr, idx = queue.popleft()

                if curr.left:
                    queue.append((curr.left, 2*idx))

                if curr.right:
                    queue.append((curr.right, 2*idx+1))
        
        return max_width
        