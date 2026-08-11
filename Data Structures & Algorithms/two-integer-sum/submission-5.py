class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # K: Compliment V: Index found
        comps = {}
        for i in range(len(nums)):
            c = target - nums[i]

            if c in comps.keys():
                return [comps[c], i]
            comps[nums[i]] = i
            
        return []
    