class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        slow = fast = 0

        k=0
        while slow < len(nums) and fast < len(nums):
            k+=1
            nums[slow] = nums[fast]
            while fast < len(nums) and nums[slow] == nums[fast]:
                fast+=1
            slow+=1

        return k
