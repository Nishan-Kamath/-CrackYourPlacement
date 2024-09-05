class Solution:
    def shortest_distance(self, matrix):
        n = len(matrix)
        
        # Convert -1 to infinity for the purposes of Floyd-Warshall algorithm
        dist = [[float('inf')] * n for _ in range(n)]
        
        # Initialize distances from the adjacency matrix
        for i in range(n):
            for j in range(n):
                if i == j:
                    dist[i][j] = 0
                elif matrix[i][j] != -1:
                    dist[i][j] = matrix[i][j]
        
        # Floyd-Warshall Algorithm
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        
        # Replace infinity with -1 for the final output
        for i in range(n):
            for j in range(n):
                if dist[i][j] == float('inf'):
                    dist[i][j] = -1
        
        # Modify the matrix in-place with the shortest distances
        for i in range(n):
            for j in range(n):
                matrix[i][j] = dist[i][j]



#{ 
 # Driver Code Starts
#Initial template for Python 

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		matrix = []
		for _ in range(n):
			matrix.append(list(map(int, input().split())))
		obj = Solution()
		obj.shortest_distance(matrix)
		for _ in range(n):
			for __ in range(n):
				print(matrix[_][__], end = " ")
			print()
# } Driver Code Ends