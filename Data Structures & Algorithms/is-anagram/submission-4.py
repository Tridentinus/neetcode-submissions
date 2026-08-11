class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
      
        sCount = {}
        tCount = {}
        for l in s:
            sCount[l] = sCount.get(l,0) + 1
        for l in t:
            tCount[l] = tCount.get(l,0) + 1
        
        if set(sCount.items()) != set(tCount.items()):

            return False

        

        return True