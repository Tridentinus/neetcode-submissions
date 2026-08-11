class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        L , R = 0, len(numbers)-1

        while L < R:
            numSum = numbers[L] + numbers[R]

            if numSum == target:
                return [L+1,R+1]
            if numSum < target:
                L+=1
            if numSum > target:
                R-=1
