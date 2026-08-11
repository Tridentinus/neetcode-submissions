class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])

        def i2mat(index):
            r = index//n
            c = index%n
            return matrix[r][c]
        
        L, R = 0, m*n-1

        while (L <= R):
            mid = L + (R-L)//2
            midVal = i2mat(mid)
            if midVal < target:
                L = mid + 1
                continue
            if midVal > target:
                R = mid - 1
                continue
            return True
        return False