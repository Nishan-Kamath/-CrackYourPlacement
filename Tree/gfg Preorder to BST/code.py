#User function Template for python3

class Node:
    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None

def constructBST(preorder, size, min_val, max_val, index):
    # Base case: If the entire preorder traversal is processed
    if index[0] == size:
        return None

    root = None
    current_value = preorder[index[0]]

    # If the current value is within the range defined by min_val and max_val,
    # it can be the root of the subtree for this part of the preorder traversal.
    if min_val < current_value < max_val:
        # Create the root node with the current value
        root = Node(current_value)
        index[0] += 1

        # Recursively build the left and right subtrees
        root.left = constructBST(preorder, size, min_val, current_value, index)
        root.right = constructBST(preorder, size, current_value, max_val, index)

    return root

def postOrderTraversal(root, result):
    if root is None:
        return
    
    # Visit left subtree
    postOrderTraversal(root.left, result)
    # Visit right subtree
    postOrderTraversal(root.right, result)
    # Visit root node
    result.append(root.data)

def Bst(pre, size) -> Node:
    index = [0]  # mutable index to track the current index in the preorder traversal
    root = constructBST(pre, size, float('-inf'), float('inf'), index)
    return root

# Function to print postorder traversal
def printPostOrder(root):
    result = []
    postOrderTraversal(root, result)
    print(" ".join(map(str, result)))


#{ 
 # Driver Code Starts
#Initial Template for Python 3


#contributed by RavinderSinghPB
class Node:

    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None


def postOrd(root):
    if not root:
        return
    postOrd(root.left)
    postOrd(root.right)
    print(root.data, end=' ')


if __name__ == '__main__':
    t = int(input())

    for _tcs in range(t):
        size = int(input())
        pre = [int(x) for x in input().split()]

        root = Bst(pre, size)

        postOrd(root)
        print()

# } Driver Code Ends