class Solution(object):
    def floodFill(self, image, sr, sc, color):
        m, n = len(image), len(image[0])
        original_color = image[sr][sc]
        if original_color == color:
            return image

        def dfs(x, y):
            if x < 0 or y < 0 or x >= m or y >= n or image[x][y] != original_color:
                return
            image[x][y] = color
            dfs(x+1, y)
            dfs(x-1, y)
            dfs(x, y+1)
            dfs(x, y-1)

        dfs(sr, sc)
        return image
        