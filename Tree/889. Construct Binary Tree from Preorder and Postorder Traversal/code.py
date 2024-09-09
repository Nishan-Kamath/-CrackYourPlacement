# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def constructFromPrePost(self, preorder, postorder):
        """
        :type preorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        root = TreeNode(preorder[0])
        stack, i = [root], 0

        for n in preorder[1:]:
            if stack[-1].val != postorder[i]:
                stack[-1].left = left = TreeNode(n)
                stack.append(left)
            else:
                while stack and stack[-1].val == postorder[i]:
                    cur = stack.pop()
                    i+=1
                stack[-1].right = right = TreeNode(n)
                stack.append(right)

        return root
