#User function Template for python3

'''	
# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''
class Solution:
    def findLCA(self, root, a, b):
        if root is None:
            return None
        
        if root.data == a or root.data == b:
            return root
        
        left_lca = self.findLCA(root.left, a, b)
        right_lca = self.findLCA(root.right, a, b)
        
        if left_lca and right_lca:
            return root
        
        return left_lca if left_lca is not None else right_lca

    # Function to find the distance from a given root to a target node
    def findDistance(self, root, target, distance):
        if root is None:
            return -1
        
        if root.data == target:
            return distance
        
        left = self.findDistance(root.left, target, distance + 1)
        if left != -1:
            return left
        
        return self.findDistance(root.right, target, distance + 1)
    
    # Main function to find the minimum distance between nodes a and b
    def findDist(self, root, a, b):
        # Step 1: Find the LCA of nodes a and b
        lca = self.findLCA(root, a, b)
        
        if lca is None:
            return -1  # If LCA is not found, return an error code
        
        # Step 2: Find the distance from the LCA to node a
        d1 = self.findDistance(lca, a, 0)
        if d1 == -1:
            return -1  # If node a is not found, return an error code
        
        # Step 3: Find the distance from the LCA to node b
        d2 = self.findDistance(lca, b, 0)
        if d2 == -1:
            return -1  # If node b is not found, return an error code
        
        # Step 4: Return the sum of the distances
        return d1 + d2

 
