from typing import List
from queue import Queue

class Solution:
    def bfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
        visited = [False] * V
        bfs_traversal = []
        q = Queue()
        q.put(0)
        visited[0] = True

        while not q.empty():
            node = q.get()
            bfs_traversal.append(node)

            for neighbor in adj[node]:
                if not visited[neighbor]:
                    q.put(neighbor)
                    visited[neighbor] = True

        return bfs_traversal