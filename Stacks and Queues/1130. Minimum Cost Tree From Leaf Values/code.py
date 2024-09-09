class Solution(object):
    def mctFromLeafValues(self, arr):
        n = len(arr)
        res = 0
        while n>1:
            Min = float('inf')
            for i in range(n-1):
                prod = arr[i]*arr[i+1]
                if prod < Min:
                    Min = prod
                    if(arr[i] < arr[i+1]):
                        idx = i
                    else:
                        idx = i+1

            res+=Min
            arr.pop(idx)
            n = len(arr)
        return res      