from typing import List

class Solution:
    def findPath(self, m: List[List[int]]) -> List[str]:
        n = len(m)
        
        def isSafe(x, y):
            return 0 <= x < n and 0 <= y < n and m[x][y] == 1 and not visited[x][y]

        def solve(x, y, path):
            if x == n - 1 and y == n - 1:
                result.append(path)
                return
            visited[x][y] = True
            if isSafe(x + 1, y):  # Move Down
                solve(x + 1, y, path + 'D')
            if isSafe(x, y - 1):  # Move Left
                solve(x, y - 1, path + 'L')
            if isSafe(x, y + 1):  # Move Right
                solve(x, y + 1, path + 'R')
            if isSafe(x - 1, y):  # Move Up
                solve(x - 1, y, path + 'U')
            visited[x][y] = False

        result = []
        visited = [[False] * n for _ in range(n)]
        if m[0][0] == 1:
            solve(0, 0, "")
        return result