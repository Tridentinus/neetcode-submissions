class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        # A-> shorter 
        A, B = nums1,nums2
        if len(A) > len(B):
            A,B = B,A

        # find size of left partition in merged array
        total = len(nums1) + len(nums2)
        half = total//2

        l,r = 0,len(A)-1
        while True:
            m_A = (l+r)//2
            m_B = (half- (m_A + 1)) - 1 # remaining elements in L partition -1
            print(f"m_A {m_A} m_B {m_B}")
            Aleft = A[m_A]      if m_A >= 0 else float("-infinity") # take none of L_A
            Aright = A[m_A+1]   if (m_A +1) < len(A) else float("infinity") #take all of L_A
            Bleft = B[m_B]      if m_B >= 0 else float("-infinity") #take none of L_B
            Bright = B[m_B+1]   if (m_B +1) < len(B) else float("infinity") # take all of L_B
            print(f"Aleft {Aleft} Aright {Aright}")
            print(f"Bleft {Bleft} Bright {Bright}")
            if Aleft <= Bright and Bleft <= Aright: #left partition done (base case)
                #odd case
                if total %2:
                    return min(Aright,Bright)
                #even case
                return (max(Aleft,Bleft) + min(Aright,Bright))/2
            elif Aleft > Bright:
                r = m_A -1 # take less of A
            else:   
                l = m_A +1 # take more of A


        