# Your task is to complete this function
# function should return true/false or 1/0
class Solution:
    def isDeadEnd(self, root):
        def checkDeadEnd(node, min_val, max_val):
            if not node:
                return False
            if min_val == max_val:
                return True
            
            return (checkDeadEnd(node.left, min_val, node.data - 1) or
                    checkDeadEnd(node.right, node.data + 1, max_val))

        return checkDeadEnd(root, 1, 10000)

