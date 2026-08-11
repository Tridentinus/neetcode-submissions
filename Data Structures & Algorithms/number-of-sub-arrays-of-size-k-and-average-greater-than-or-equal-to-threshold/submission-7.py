class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        if len(arr) < k:
            return 0

        
        res = 0
        avg = sum(arr[:k-1])/k

        for L in range(len(arr)-k+1):
            avg += arr[L+k-1]/k
            if avg >= threshold:
                res+=1
            avg-=arr[L]/k
        return res