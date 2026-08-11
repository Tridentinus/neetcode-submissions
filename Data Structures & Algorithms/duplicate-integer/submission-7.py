class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        '''
        seen = Set()
        * for each item in the array
            if unseen add to set of seen
            
            if seen return True

        return False
        '''
        seen = set()
        for n in nums: 
            if n in seen:
                return True
            else:
                seen.add(n)
        return False
        