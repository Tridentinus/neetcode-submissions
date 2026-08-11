class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # K : comp
        # V : index

        comps = {}

        for i in range(len(nums)):
            #if seen complement we are done
            if nums[i] in comps.keys():
                return [comps[nums[i]], i]

            # note the index of the current value of for future complement encounter
            comps[target-nums[i]] = i
