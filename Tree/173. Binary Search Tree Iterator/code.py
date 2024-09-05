# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator(object):

    def __init__(self, root):
        self.arr = []
        self.idx = 0
        self.inOrder(root)
        print(self.arr)

    def inOrder(self,root):
        if not root:
            return
        self.inOrder(root.left)
        self.arr.append(root.val)
        self.inOrder(root.right)
        

    def next(self):
        val = self.arr[self.idx]
        self.idx+=1
        return val
        

    def hasNext(self):
        return self.idx <= len(self.arr)-1

        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()