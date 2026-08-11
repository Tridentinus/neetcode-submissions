class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])

        l = 0
        r = m * n - 1
        while l <= r:
            mid = l + ((r-l)//2)
            if target > matrix[(mid)//n][(mid%n)]:
                l = mid + 1
            elif target < matrix[(mid)//n][(mid%n)]:
                r = mid -1
            else:
                return True
        return False