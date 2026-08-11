class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        

        strDict = defaultdict(list)

        for string in strs:
            
            lCount = [0] * 26
            for l in string:
              
                lCount[ord(l)-97] += 1
            
            strDict[tuple(lCount)].append(string)
        return list(strDict.values())
