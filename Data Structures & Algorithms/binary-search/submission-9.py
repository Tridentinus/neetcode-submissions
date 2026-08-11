class Solution:
    def search(self, nums: List[int], target: int) -> int:
        L, R = 0 , len(nums) -1
        while L <= R:

            mid = (R + L)//2

            if nums[mid] < target:
                L = mid + 1
                continue
            if nums[mid] > target:
                R = mid - 1
                continue
            return mid
        return -1

