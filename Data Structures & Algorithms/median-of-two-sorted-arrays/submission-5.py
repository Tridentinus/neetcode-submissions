class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A,B = nums1,nums2
        m,n = len(A),len(B)
        total = m + n 
        half = total //2

        if len(B) < len(A):
            A,B = B,A
        
        l ,r = 1, len(A)

        while True:
            i = (l+r)//2
            j = half - i

            Aleft = A[i-1] if i-1 >=0 else float("-infinity")
            Aright = A[i] if (i) < len(A) else float("infinity")
            Bleft = B[j-1] if j-1 >=0 else float("-infinity")
            Bright = B[j] if (j) < len(B) else float("infinity")

            if Aleft <= Bright and Bleft <= Aright:
                if total %2:
                    return min(Aright,Bright)
                return (max(Aleft,Bleft) + min(Aright,Bright))/2

            elif Aleft > Bright:
                r = i - 1
            else:
                l = i + 1
        

