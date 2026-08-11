class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        

        def enough(k):
            if k == 0:
                return False
            h_taken = 0
            for pile in piles:
                h_taken += math.ceil(pile/k)
            return h_taken <= h
        

        def oracle(k):
            if not enough(k):
                return 1
            if enough(k-1):
                return -1
            return 0

        L, R = 1, max(piles)

        while L<= R:
            mid = L + (R-L)//2

            if oracle(mid) == 1:
                L = mid + 1
                continue
            if oracle(mid) == -1:
                R = mid - 1 
                continue
            return mid
