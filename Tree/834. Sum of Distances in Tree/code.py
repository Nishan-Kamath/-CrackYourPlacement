from collections import defaultdict

class Solution(object):
    def sumOfDistancesInTree(self, n, edges):
        tree = defaultdict(list)
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        subtree_sizes = [0] * n
        dist_sum = [0] * n

        def dfs(node, parent):
            size = 1
            distance = 0
            for child in tree[node]:
                if child != parent:
                    dfs(child, node)
                    size += subtree_sizes[child]
                    distance += subtree_sizes[child] + dist_sum[child]
            subtree_sizes[node] = size
            dist_sum[node] = distance

        dfs(0, -1)

        ans = [0] * n
        ans[0] = dist_sum[0]
        def dfs2(node, parent):
            for child in tree[node]:
                if child != parent:
                    ans[child] = ans[node] - subtree_sizes[child] + n - subtree_sizes[child]
                    dfs2(child, node)
        
        dfs2(0, -1)
        
        return ans