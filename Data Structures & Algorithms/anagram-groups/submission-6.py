class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        

        hashmap = defaultdict(list)

        for s in strs:
            c = [0]*26

            for l in s:
                c[ord(l)-ord("a")] +=1
            hashmap[tuple(c)].append(s)

        return hashmap.values()
