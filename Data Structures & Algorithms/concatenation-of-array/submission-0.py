class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        
        size = len(nums)
        arr = [0] * size *2

        for i in range(size):
            arr[i] = arr[size + i] = nums[i]
        return arr